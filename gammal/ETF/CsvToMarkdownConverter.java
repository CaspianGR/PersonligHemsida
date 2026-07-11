import java.io.IOException; // Needed for file IO exceptions
import java.nio.file.Files;  // Modern file IO class
import java.nio.file.Path;   // Represents a file path
import java.nio.file.Paths;  // Utility to get Path objects
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors; // Needed for joining lines back if using readAllLines

public class CsvToMarkdownConverter {

    /**
     * Converts a CSV formatted string into a Markdown table string.
     * (Original function - details omitted for brevity, see previous answer)
     *
     * @param csvString The string containing the CSV data.
     * @return A string formatted as a Markdown table, or an empty string if input is null/empty or contains no valid data.
     */
    public static String convertCsvToMarkdown(String csvString) {
        if (csvString == null || csvString.trim().isEmpty()) {
            return "";
        }

        // Split into lines, handling both \n and \r\n, and filter out empty lines
        List<String> lines = Arrays.stream(csvString.split("\\r?\\n"))
                .map(String::trim)
                .filter(line -> !line.isEmpty())
                .toList();

        if (lines.isEmpty()) {
            return "";
        }

        // --- Parse Header ---
        String headerLine = lines.get(0);
        List<String> headers = Arrays.stream(headerLine.split(","))
                .map(String::trim)
                .toList();
        int columnCount = headers.size();

        if (columnCount == 0) {
            return "";
        }

        // --- Parse Data Rows ---
        List<List<String>> dataRows = new ArrayList<>();
        if (lines.size() > 1) {
            for (int i = 1; i < lines.size(); i++) {
                List<String> cells = new ArrayList<>(Arrays.asList(lines.get(i).split(",")));
                while (cells.size() < columnCount) {
                    cells.add("");
                }
                if (cells.size() > columnCount) {
                    cells = cells.subList(0, columnCount);
                }
                List<String> trimmedCells = cells.stream().map(String::trim).toList();
                dataRows.add(trimmedCells);
            }
        }

        // --- Build Markdown Table ---
        StringBuilder markdownTable = new StringBuilder();

        // Header Row
        markdownTable.append("| ");
        headers.forEach(header -> markdownTable.append(header).append(" | "));
        markdownTable.append("\n");

        // Separator Row
        markdownTable.append("|");
        for (int i = 0; i < columnCount; i++) {
            markdownTable.append("---|");
        }
        markdownTable.append("\n");

        // Data Rows
        dataRows.forEach(row -> {
            markdownTable.append("| ");
            row.forEach(cell -> markdownTable.append(cell).append(" | "));
            markdownTable.append("\n");
        });

        return markdownTable.toString();
    }

    /**
     * Reads a CSV file from the specified path and converts its content
     * into a Markdown table string.
     *
     * Uses the convertCsvToMarkdown(String) method internally after reading the file.
     * Shares the same limitations regarding complex CSV structures (quoted fields).
     * Requires Java 11+ for Files.readString().
     *
     * @param filePath The path to the .csv file.
     * @return A string formatted as a Markdown table, or an empty string if the file
     *         cannot be read, is empty, or contains no valid data.
     */
    public static String convertCsvFileToMarkdown(String filePath) {
        if (filePath == null || filePath.trim().isEmpty()) {
            System.err.println("Error: File path cannot be null or empty.");
            return "";
        }

        Path path = Paths.get(filePath);

        if (!Files.exists(path)) {
            System.err.println("Error: File not found at path: " + filePath);
            return "";
        }
        if (!Files.isReadable(path)) {
            System.err.println("Error: Cannot read file (check permissions): " + filePath);
            return "";
        }

        try {
            // Read the entire file content into a single string (Requires Java 11+)
            String csvContent = Files.readString(path);

            // Use the existing method to perform the conversion
            return convertCsvToMarkdown(csvContent);

        } catch (IOException e) {
            System.err.println("Error reading file: " + filePath + " - " + e.getMessage());
            return ""; // Return empty string on error
        } catch (OutOfMemoryError e) {
            System.err.println("Error: File is too large to read into memory: " + filePath);
            return "";
        }
    }

    // --- Example Usage ---
    public static void main(String[] args) throws IOException { // Added throws for temp file creation

        // --- Example using the original string-based method ---
        System.out.println("--- String Input Test ---");
        String csvData = """
                         Name, Age, City
                         Alice, 30, New York
                         Bob, 24, Paris
                         """;
        String markdownFromString = convertCsvToMarkdown(csvData);
        System.out.println(markdownFromString);

        // --- Example using the new file-based method ---
        System.out.println("--- File Input Test ---");

        // Create a temporary CSV file for the example
        Path tempFile = null;
        try {
            tempFile = Files.createTempFile("test_data", ".csv");
            String fileCsvContent = """
                                    Product ID, Item Name, Price
                                    P101, Gadget, 19.99
                                    P102, Widget, 25.50
                                    P103, Thingamajig, 9.75
                                    """;
            Files.writeString(tempFile, fileCsvContent); // Write content to temp file

            System.out.println("Created temporary file: " + tempFile.toAbsolutePath());

            // Convert the CSV file to Markdown
            String markdownFromFile = convertCsvFileToMarkdown(tempFile.toString());

            if (!markdownFromFile.isEmpty()) {
                System.out.println("Markdown from file:");
                System.out.println(markdownFromFile);
            } else {
                System.out.println("Conversion from file failed or produced empty result.");
            }

            // --- Test non-existent file ---
            System.out.println("\n--- Non-Existent File Test ---");
            String markdownFromBadFile = convertCsvFileToMarkdown("inveteringETF2.csv");
            System.out.println("Result for non-existent file: '" + markdownFromBadFile + "' (Expected empty string and error message)");


        } catch (IOException e) {
            System.err.println("Error during temporary file creation/writing: " + e.getMessage());
        } finally {
            // Clean up the temporary file
            if (tempFile != null) {
                try {
                    Files.deleteIfExists(tempFile);
                    System.out.println("Deleted temporary file: " + tempFile.toAbsolutePath());
                } catch (IOException e) {
                    System.err.println("Error deleting temporary file: " + tempFile + " - " + e.getMessage());
                }
            }
        }
    }
}
