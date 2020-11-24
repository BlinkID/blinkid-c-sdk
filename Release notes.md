# Release notes

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
