# Release notes

## 5.9.0

### New additions to our supported documents list

- 53 documents added:

	- ALBANIA - DL (front)
	- BELGIUM - RESIDENCE PERMIT (front, back)
	- BOLIVIA - ID (front, back)
	- BOSNIA AND HERZEGOVINA - PASSPORT
	- CAMBODIA - PASSPORT
	- CANADA - RESIDENCE PERMIT (front, back)
	- CANADA - MANITOBA - ID (front)
	- CANADA - ONTARIO - HEALTH INSURANCE CARD (front)
	- CHILE - ALIEN ID (front, back)
	- CHINA - ID (front, back)
	- COLOMBIA - MINORS ID (front, back)
	- CYPRUS - RESIDENCE PERMIT (front, back)
	- CZECHIA - PASSPORT
	- GREECE - ID (front)
	- HAITI - ID (front, back)
	- ITALY - RESIDENCE PERMIT (front, back)
	- LATVIA - DL (front)
	- LATVIA - PASSPORT
	- LITHUANIA - PASSPORT
	- LUXEMBOURG - DL (front)
	- MONTENEGRO - DL (front)
	- MONTENEGRO - ID (front, back)
	- MONTENEGRO - PASSPORT
	- NETHERLANDS - RESIDENCE PERMIT (front, back)
	- NICARAGUA - ID (front, back)
	- NIGERIA - ID (front, back)
	- NORWAY - RESIDENCE PERMIT (front, back)
	- OMAN - RESIDENT ID (front, back)
	- PARAGUAY - DL (front, back)
	- PERU - DL (front, back)
	- PHILIPPINES - SOCIAL SECURITY CARD (front)
	- ROMANIA - PASSPORT
	- RUSSIA - PASSPORT
	- SERBIA - PASSPORT
	- SLOVAKIA - PASSPORT
	- SLOVENIA - PASSPORT
	- SOUTH KOREA - DL (front)
	- SPAIN - RESIDENCE PERMIT (front, back)
	- SWEDEN - RESIDENCE PERMIT (front, back)
	- THAILAND - PASSPORT
	- UKRAINE - DL (front)
	- UKRAINE - PASSPORT
	- USA - ARKANSAS - ID (front, back)
	- USA - CONNECTICUT - ID (front, back)
	- USA - GREEN CARD (front, back)
	- USA - MARYLAND - ID (front, back)
	- USA - MINNESOTA - ID (front, back)
	- USA - NEVADA - ID (front, back)
	- USA - NEW YORK CITY - ID (front, back)
	- USA - TEXAS - WEAPON PERMIT (front)
	- USA - VIRGINIA - ID (front, back)
	- VENEZUELA - DL (front)
	- VENEZUELA - PASSPORT

- Beta support added for 46 documents:
	- ALBANIA - PASSPORT
	- BAHAMAS - DL (front)
	- BERMUDA - DL (front)
	- BOLIVIA - DL (front)
	- CHILE - DL (front)
	- COLOMBIA - ALIEN ID (front)
	- DENMARK - RESIDENCE PERMIT (front, back)
	- DOMINICAN REPUBLIC - DL (front, back)
	- ECUADOR - DL (front)
	- EL SALVADOR - DL (front, back)
	- ESTONIA - RESIDENCE PERMIT (front, back)
	- GUATEMALA - DL (front, back)
	- HAITI - DL (front)
	- HONDURAS - DL (front, back)
	- HONDURAS - ID (front, back)
	- HUNGARY - ADDRESS CARD (front, back)
	- HUNGARY - RESIDENCE PERMIT (front)
	- ICELAND - DL (front)
	- ISRAEL - ID (front, back)
	- JAPAN - DL (front)
	- JORDAN - DL (front)
	- LATVIA - ALIEN PASSPORT
	- LATVIA - RESIDENCE PERMIT (front, back)
	- LUXEMBOURG - RESIDENCE PERMIT (front)
	- MALTA - RESIDENCE PERMIT (front, back)
	- MEXICO - BAJA CALIFORNIA - DL (front)
	- MEXICO - CHIHUAHUA - DL (front)
	- MEXICO - CIUDAD DE MEXICO - DL (front)
	- MEXICO - PROFESSIONAL DL (front)
	- MEXICO - GUANAJUATO - DL (front)
	- MEXICO - MICHOACAN - DL (front)
	- MEXICO - TAMAULIPAS - DL (front, back)
	- MEXICO - VERACRUZ - DL (front, back)
	- PHILIPPINES - TAX ID (front)
	- PHILIPPINES - VOTER ID (front)
	- POLAND - RESIDENCE PERMIT (front, back)
	- PORTUGAL - RESIDENCE PERMIT (front, back)
	- PUERTO RICO - VOTER ID (front)
	- SLOVAKIA - RESIDENCE PERMIT (front, back)
	- SOUTH KOREA - ID (front)
	- SWITZERLAND - RESIDENCE PERMIT (front, back)
	- TAIWAN - TEMPORARY RESIDENCE PERMIT (front)
	- TURKEY - RESIDENCE PERMIT (front)
	- USA - KANSAS - ID (front, back)
	- VENEZUELA - ID (front)
	- VIETNAM - DL (front)

- Added back side support for 7 documents:
	- ARGENTINA - ID
	- ECUADOR - ID
	- FINLAND - ID
	- NIGERIA - DL
	- QATAR - RESIDENCE PERMIT
	- URUGUAY - ID
	- USA - NEW YORK - DL

- 9 documents are no longer beta:
	- BRAZIL - DL
	- CANADA - ALBERTA - ID
	- MALAYSIA - MyKAS
	- MEXICO - NUEVO LEON - DL
	- PANAMA - DL
	- PORTUGAL - DL
	- SAUDI ARABIA - ID
	- SRI LANKA - ID
	- USA - IDAHO - ID

### New features and updates to the BlinkId(Combined)Recognizer

*   We’re now able to read partial MRZ formats (2.5 lines), like the ones found on Switzerland and Lichtenstein DLs.
*   We’ve added `**documentOptionalAdditionalNumber**` to the main part of the result, as well as front and back side VIZ results.
*   We’ve expanded the set of possible recognizer states with `**RECOGNIZER_RESULT_STATE_STAGE_VALID**`. This state enables better control of the Combined scanning pipeline. It activates when the first side of a document has been successfully scanned and scanning of the second side is required.

### Fixes

*   We’ve fixed an uncommon bug where you’d get incomplete results upon scanning of the MRZ with the `allowUnparsed` setting enabled.
*   We've changed `MRTD_TYPE_IDENITY_CARD` to `MRTD_TYPE_IDENTITY_CARD` (fixed typo)

## 5.8.1

- fixed a rare crash that could occur when using online license on a device with unstable network connection
- SDK is now thread safe under specific conditions
    - those conditions are now documented
- added Barcode recognizer

## 5.8.0

### New additions to our supported documents list
#### Plastic page passports
We added support for scanning the visual inspection zone - VIZ includes everything except MRZ or barcode. Keep in mind that BlinkID scans and extracts data only from the VIZ that is on the first **plastic page** found in the passport list below:

* **Chile** Passport (BETA)
* **Colombia** Passport
* **Croatia** Passport
* **Denmark** Passport
* **Finland** Passport (BETA)
* **Germany** Passport
* **Hong Kong** Passport (BETA)
* **Ireland** Passport (BETA)
* **Malaysia** Passport
* **Netherlands** Passport
* **New Zealand** Passport
* **Norway** Passport
* **Singapore** Passport
* **South Africa** Passport
* **Sweden** Passport
* **Turkey** Passport (BETA)
​
#### Vertical US documents
* **California** ID
* **Illinois** ID
* **New York** ID
* **North Carolina** ID
* **Texas** ID
​
#### Other documents
* **Canada** Newfoundland and Labrador DL
* **Croatia** Residence Permit (BETA)
* **Guatemala** Consular ID
* **Malaysia** MyKAS (BETA)
* **Mexico** Jalisco DL / front side only
* **Mexico** Nuevo Leon DL (BETA)
* **Peru** ID (BETA)
* **Singapore** S Pass (BETA)
* **Uruguay** ID / front side only
* **USA** Missouri ID
* **USA** Texas ID

#### European DLs with a single line MRZ
BlinkID extracts data from driver’s licenses that contain single line MRZ:

* **Croatia** DL
* **Estonia** DL
* **France** DL
* **Ireland** DL
* **Netherlands** DL
* **Slovakia** DL

#### Back side supported on:
* **Azerbaijan** ID
* **Singapore** DL
* **Singapore** Employment Pass

#### No longer BETA
* **Slovakia** DL

### New features and updates in BlinkID(Combined)Recognizer
* We added `signatureImage` to the result. Extract signature image from the documents below:
	* Australia Victoria DL
	* Austria ID
	* Austria DL
	* Brunei Military ID
	* Colombia ID
	* Croatia ID (on 2013 and 2015 versions)
	* Cyprus ID
	* Czechia ID (on the 2012 version)
	* Germany ID (2010 version)
	* Germany DL (2013 version)
	* Indonesia ID
	* Ireland DL
	* Italy DL
	* Mexico Voter ID
	* New Zealand DL
	* Slovenia ID
	* Spain DL
	* Sweden DL
	* Switzerland ID
	* UAE ID
	* UAE Resident ID

* We enabled extraction of the **date of birth** from the **NRIC** from Malaysian documents:
	* MyKad
	* MyKas
	* MyKid
	* MyPR
	* MyTentera


* We added anonymization support for:
	* MRZ (OPT2 containing the ID number) on China Mainland Travel Permit Hong Kong
	* MRZ (Document number) on Germany Alien Passport
	* Document number, MRZ (Document number) on Germany ID
	* MRZ (Document number) on Germany Minors Passport
	* MRZ (Document number) on Germany Passport
	* Document number on Hong Kong ID
	* MRZ (Document number, OPT1 containing the passport or ID number) on Hong Kong Passport
	* Personal ID number on Netherlands DL
	* Personal ID number, MRZ (OPT1 containing the BSN) on Netherlands ID
	* MRZ (OPT1 containing the BSN) on Netherlands Passport
	* Document number on Singapore DL
	* Personal ID number on Singapore Employment Pass
	* Document number on Singapore FIN Card
	* Document number on Singapore ID
	* MRZ (Document number, OPT1 containing the NRIC) on Singapore Passport
	* Document number on Singapore Resident ID
	* Document number on Singapore S Pass
	* Personal ID number on Singapore Work Permit
	* MRZ (OPT1 containing the resident registration number) on South Korea Diplomatic Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Residence Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Service Passport
	* MRZ (OPT1 containing the resident registration number) on South Korea Temporary Passport
* We improved MRZ data extraction on:
	* **Russia Passport**

### Other features and updates

* We added the field `middleName` to BlinkID(Combined)Recognizer and IDBarcodeRecognizer results. This field is extracted from AAMVA standard compliant barcodes, whenever available.

### Fixes
* We improved the data match logic for **Guatemala Consular ID** in BlinkID(Combined)Recognizer.

### C SDK specific changes

- Added features that already exist in mobile SDKs:
    - Added `signatureImage` to the result structure
    - Added `ImageOptions` for captured images of the person's photograph and signature
    - Added `FullDocumentImageOptions` for captured images of the ID card which contains more options than `ImageOptions`
    - Added `ExtensionFactors` option for specifying the extensions relative to the retrieved image
- Minor API change:
    - changed `genericIdSettings` to `baseSettings` in `MBBlinkIdCombinedRecognizerSettings`
- Added support for Windows
    - only 64-bit Windows 10 is supported
        - 32-bit Windows 10, as well as Windows 8.1 and earlier versions of Windows are **not supported**
    - [Visual C++ 2019 redistributable package](https://aka.ms/vs/16/release/VC_redist.x64.exe) is required for BlinkID SDK to work on Windows
- The Linux version now requires the `OpenSSL v1.1.1` package for the SDK to operate.
    - check the updated [integration guide](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#sw-requirements) for more information

## 5.7.0

- This is the initial release of the new BlinkID C SDK. The new C SDK is built from the same building blocks as our mobile and web solutions, enabling state of the art identity document scanning through a flexible C API.
- For scanning only the front side of an identity document or any MRTD (including passports and visas), see [BlinkIDRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#blinkidRecognizer).
- For scanning both sides of an identity document as well as any MRTD (including passports and visas), see [BlinkIDCombinedRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#blinkidCombinedRecognizer).
    - A list of all supported documents can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/BlinkIdRecognizer.md).
    - A list of extracted fields on the supported documents can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/BlinkIdDocumentFields.md).
- For scanning barcodes on identity documents and extracting parsed barcode data, see [IdBarcodeRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#idBarcodeRecognizer).
    - A list of supported IDs with barcodes can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/IdBarcodeRecognizer.md).
