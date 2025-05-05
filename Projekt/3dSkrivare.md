## 3d skrivare

## Mål

Mållet med den här skrivaren är att bygga en relativt snabb 3d skivar som upfyller följande mål

- 450c pipa
- 90c kammare
- 100c plata
- Få plats i rammen jag reda har
- Möjlighet att vattenkyla Stegmotoren och cold end om märmeskölden inte fungerar
- Integrerad och automatisk brandsläkare
- Stor skärm för operatören
- Integreradt filltrerings system till utsug och stöd för att kunna ärseta all luft i kommaren när en utskriften är förding
- Bra nog isolation så att utsidan är inte varm
- Ordentlig och över spekad el system

## Komponenter

### Kropen

Baserad på en Mingda Glitar 6c

### X Y axel ram

xy Axlen är en modefierad [Monolith Gantry](https://github.com/CloakedWayne/Monolith_Gantry_V2-VThttps:/) där jag har ampasat dimetionerna så att de får plats i ramen och jag har ärsat 3030 aluminom extrusion med 30x30 stål rör och 30x20 stål rör för y axlen eftersom att den är mindere. De stål platter som kommer krävas för Monolith Gantry kommer skäras ut av någon lokalt företag, stålrören kommer köpal lokalt och hålen kommer boras på ETF, och alla kommponenetr kommer köpas uta av [3dkatten](https://www.3dkatten.se/ "https://www.3dkatten.se")

---



### Z axel

Tills vidar kommer jag behåla den ursprungliga z axlen men jag kommer nog upgradera till en 3 punkt dynamisk plata i framtiden

---



### Extruder

Det fins 3 alternativ hur jag vill göra med dellen som mattar plast

1. [BondTech idax](https://www.bondtech.se/indx-by-bondtech/)(har inte sleps när jag skriver detta)
   1. problemet med detta alternativet är att den inte når temperaturen jag vill
   2. ett annat är att den inte kommer passa med systemet jag har som en värmesköld
   3. Fördelen är att det är en tool changer
2. [LGX PRO](https://www.bondtech.se/product/lgx-pro-large-gears-extruder/) + [LGX ACE Magnum](https://www.bondtech.se/product/lgx-ace-magnum-plus-hotend/)
   1. Problemet med den här vallet är att den kommer vara lagom dyr och väga ganska mycket
   2. fördel är att den är en hålfast design som kommer hålla och låta mig printa ganska snabbt eller värkligen smälta plasten
3. [Calamity Toolhead](https://www.lukeslabonline.com/products/calamity-toolhead-electronics-fans?pr_prod_strat=e5_desc&pr_rec_id=733d66568&pr_rec_pid=9254720569645&pr_ref_pid=9738161357101&pr_seq=uniform)(eller en annan all metal design som använder en [Chube conduction](https://www.lukeslabonline.com/products/chube-conductionhttps:/) eller [Chube Air](https://www.lukeslabonline.com/products/chube-air) )
   1. största nakdelen är att den väget ett halft ton och kommer kosta en förmögenhet
   2. fördellar är att den kommer kuna smälta enorma mengder plast och snapt kyla ner de
4. [Chube conduction](https://www.lukeslabonline.com/products/chube-conductionhttps:/) + [Chube Conduction  LGX Water Block](https://www.lukeslabonline.com/products/chube-conduction-water-block) eller [LGX Champ Adapter](https://www.lukeslabonline.com/products/chube-lgx-champ?pr_prod_strat=e5_desc&pr_rec_id=590d7d986&pr_rec_pid=9569019363629&pr_ref_pid=9675655446829&pr_seq=uniform) + [LGX PRO](https://www.bondtech.se/product/lgx-pro-large-gears-extruder/)
   1. Största nakdelen är att den inte kommer vara så stabil och om vaten varianten avänds så måste jag dra vattenkylning
   2. fördellar är att den kommer kuna smälta enorma mengder plast och att den är vattenkyld så om jag endå behöver dra vatenkylning så är den använbar



---



### Electronik

- xy axlen kommer använda [LDO-42STH48-2504AHS8 S55](https://3dkatten.se/products/ldo-42sth48-2504ahs8-s55-1) stegmotorer tills vidar
- [Duet 3d](https://www.duet3d.com/) kommer användas för all kontrol electronik
  - [Duet 3 Mini 5+](https://www.duet3d.com/duet3mini5plus) för kontroll av skrivaren
  - [Duet 3 Tool Board 1LC](https://www.duet3d.com/duet3toolboard1lc) eller [Duet 3 Roto Toolboard](https://www.duet3d.com/Duet3RotoToolboard) för att göra kabeldragningen till huvodet enklare
  - [Duet 3 Scanning Z Probe](https://www.duet3d.com/Duet3ScanningZProbe) för att skanna platan
  - [Duet 3 Mini 2+](https://www.duet3d.com/duet3expansionmini2plus) om jag behöver 2 extra motorer om jag använder 3(z) och 4(x och y) stegmotore
  - [Duet3D Roto Filament Monitor](https://www.duet3d.com/rotofilamentmonitor) eller [Duet3D Filament Monitor](https://www.duet3d.com/filamentmonitor) för att dettektera och varna mig när någonting är fell med matningen av plasten
- 24v ac och 230v dc systemet har inte mestämtes en
