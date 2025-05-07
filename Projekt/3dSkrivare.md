## 3d skrivare

## Mål

Mållet med den här skrivaren är att bygga en relativt snabb 3D-skrivare som uppfyller följande mål:

- 450 °C pipa
- 90 °C kammare
- 100 °C platta
- Få plats i ramen jag redan har
- Möjlighet att vattenkyla stegmotorn och cold end om värmeskölden inte fungerar
- Integrerad och automatisk brandsläckare
- Stor skärm för operatören
- Integrerat filtreringssystem till utsug och stöd för att kunna ersätta all luft i kammaren när utskriften är färdig
- Tillräckligt bra isolering så att utsidan inte är varm
- Ordentligt och överspecat elsystem

## Botiker

- [Motedis](https://www.motedis.se/se)
- [3dkatten](https://www.3dkatten.se/ "https://www.3dkatten.se")
- [BondTech](https://www.bondtech.se/)
- [Lukes Lab](https://www.lukeslabonline.com/)


## Komponenter

### Kropen

Baserad på en Mingda Glitar 6c

### X Y axel ram

xy Axlen är en modefierad [Monolith Gantry](https://github.com/CloakedWayne/Monolith_Gantry_V2-VThttps:/) där jag har anpassat dimensionerna så att de får plats i ramen och jag har ersatt 3030 aluminium extrusion med 30x30 stålrör och 30x20 stålrör för Y-axeln eftersom den är mindre. De stålplattor som kommer att krävas för Monolith Gantry kommer att skäras ut av något lokalt företag, stålrören kommer att köpas lokalt och hålen kommer att borras på ETF, och alla komponenter mådellar som behöves till Monolith Gantry kommer köpas från [3dkatten](https://www.3dkatten.se/ "https://www.3dkatten.se")
Kommmer använda 9mm gt3 belten eftersom att dem är styvare 

---

### Z axel

Tills vidare kommer jag behålla den ursprungliga Z-axeln, men jag kommer nog uppgradera till en trepunkts dynamisk platta i framtiden.

---

### Extruder

Det fins 3 alternativ hur jag vill göra med dellen som mattar plast

1. [BondTech idax](https://www.bondtech.se/indx-by-bondtech/)(har inte sleps när jag skriver detta)
   1. Problemet med detta alternativ är att det inte når den temperatur jag vill ha.
   2. Ett annat är att det inte kommer att passa med systemet jag har som värmesköld.
   3. Fördelen är att det är en tool changer.
2. [LGX PRO](https://www.bondtech.se/product/lgx-pro-large-gears-extruder/) + [LGX ACE Magnum](https://www.bondtech.se/product/lgx-ace-magnum-plus-hotend/)
   1. Problemet med det här valet är att det kommer att vara lagom dyrt och väga ganska mycket.
   2. Fördelen är att den är en hållfast design som kommer att hålla och låta mig printa ganska snabbt eller verkligen smälta plasten.
3. [Calamity Toolhead](https://www.lukeslabonline.com/products/calamity-toolhead-electronics-fans?pr_prod_strat=e5_desc&pr_rec_id=733d66568&pr_rec_pid=9254720569645&pr_ref_pid=9738161357101&pr_seq=uniform)(eller en annan all metal design som använder en [Chube conduction](https://www.lukeslabonline.com/products/chube-conduction) eller [Chube Air](https://www.lukeslabonline.com/products/chube-air) )
   1. Största nackdelen är att den väger ett halvt ton och kommer att kosta en förmögenhet.
   2. Fördelarna är att den kommer att kunna smälta enorma mängder plast och snabbt kyla ner dem.
4. [Chube conduction](https://www.lukeslabonline.com/products/chube-conductionhttps:/) + [Chube Conduction  LGX Water Block](https://www.lukeslabonline.com/products/chube-conduction-water-block) eller [LGX Champ Adapter](https://www.lukeslabonline.com/products/chube-lgx-champ?pr_prod_strat=e5_desc&pr_rec_id=590d7d986&pr_rec_pid=9569019363629&pr_ref_pid=9675655446829&pr_seq=uniform) + [LGX PRO](https://www.bondtech.se/product/lgx-pro-large-gears-extruder/)
   1. Största nackdelen är att den inte kommer att vara så stabil, och om vattenvarianten används så måste jag dra vattenkylning.
   2. Fördelarna är att den kommer att kunna smälta enorma mängder plast, och att den är vattenkyld så om jag ändå behöver dra vattenkylning så är den användbar.

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
