# Stratasys uPrint

## Bakgrund

Har velat jobba på en ht Skrivare ganska länge så när de visade sig att [Helsingborg Makerspace](https://helsingborgmakerspace.se/)

fick in a Stratasys uPrint så blev jag väldigt intreserad att fixa den.

## Komponeter

### Kammare

Skrivarens kommare är rubost och väll isulerad. 

Enligt folk på nätet sa ska man inte gå över 90c kammare på Stratasys uPrint.

Detta gör att vi kan printa ABS, PET, visa PA, och kanske PC.

### Huvod

Detta är den dellen av skivaren som kommer förmodligen kommer endras.
uPrint använder ett vikande huvod som gör att den kan välja mellan två material, den mekanismen kommer vi nog inte byta up. Problemet är att pipan är praktiskt taget en tup, och ett set av två sådana kostar 3k. Detta kommer vara ett problem om vi vill ha en pipa pär material så att vi inte blandar dem.
Har funderat på omm man kan antingen SLM skiva ut ett nyt block som kan ta v6 pipor, montera typ chube eller volcano hotends, eller om vi behöver byta ut hella huvoded med chube + lgx.

### Electronik

Detta kommer behöva ärsetas hellt eftersom att jag vill köra mjukvara som inte är äldre en mig på skrivaren.
Vi kommer ärseta den med en Duet3 och använda [de här adapter kortet]([https://github.com/jcwebber93/DuePrint3/]) designat av [sebkritikel](https://discord.com/channels/840596987522056232/840883984715218965/1480506571359387790). Vilket gör att vi kan använda RRF

### Bord

Skrivaren behöver ett nyt bord eftersom att skrivaren är >40kg och två av hjulen har rendan böjt. Skrivaren har monterings håll på undersidan där du kan läga till en till material hållare vilka vi kan avända för att montera den på ett bättre bord

### Material förvaring

I nuläget avände skrivaren två kaseter för plaste, desa tar bara stratasys inke standard rullar plas vilket gör det svärt att köpa in ny plast. Det fin plast för en standard rulle i kaset hålaren så vi kan designa nya kaseter. Jag gillar kaset konseptet eftersom att de tvingar operatören att hålla plaste tor hella tiden
