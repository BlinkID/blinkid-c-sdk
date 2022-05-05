# Release notes

## 5.16.0

### We've added new documents to our list of supported documents:

#### Europe

- Austria - ID Card (front only)
- Germany - ID Card

#### Latin America and the Caribbean

- Brazil - ID Card (beta)
- Colombia - ID Card (front only)
- Ecuador - ID Card

#### Mexico

- Baja California Sur - Driving Licence (beta)
- Ciudad De Mexico - Driving Licence (front only)
- Colima - Driving Licence (front only, beta)
- Michoacan - Driving Licence (beta)
- Nayarit - Driving Licence (beta)
- Quintana Roo Solidaridad - Driving Licence (front only)
- Tlaxcala - Driving Licence
- Veracruz - Driving Licence (beta)

#### Oceania

- Australia - Northern Territory (beta)

#### Asia

- Japan - My Number Card (front only)
- Singapore - Resident ID

#### Northern America

- USA - Missouri - ID Card
- USA - Nevada - Driving Licence
- USA - New York City - ID Card
- USA - Oklahoma - ID Card

#### Back side support added:

- Mexico - Chiapas - Driving License

#### No longer BETA:

- Mexico - Baja California - Driving Licence
- Mexico - Chihuahua - Driving Licence
- Mexico - Coahuila - Driving Licence
- Mexico - Guanajuato - Driving Licence
- Mexico - Mexico - Driving Licence

### Changes to BlinkID(Combined) Recognizer

- Added the setting `saveCameraFrames` for saving camera frames with the default value being `false`. Note that the memory consumption is a bit bigger if this setting is set to `true`.
	- New result members are available for:
		- BlinkIDRecognizer:`cameraFrame` and `barcodeCameraFrame`.
		- BlinkIDCombinedRecognizer:`frontCameraFrame`, `backCameraFrame`, and `barcodeCameraFrame`.
- We've added new result members when scanning Australian Driving Licences: `vehicleClass`, `licenceType`, `effectiveDate` and `expiryDate`.
	- Result members are displayed under the `VehicleClassInfo` field; we can also extract data from multiple rows when this vehicle class info data is present on the document (e.g. multiple expiry dates for different vehicle classes).
- We've added new enum values:
	- Region: `QUINTANA_ROO`, `QUINTANA_ROO_SOLIDARIDAD`, `TLAXCALA` which are available when scanning Mexican Driving Licences.
	- Type: `MY_NUMBER_CARD` which is available when scanning Japanese My Number Card documents.
- We've added new result member `additionalOptionalAddressInformation` which gives additional address information about the document owner.
	- This result member can be present when scanning the Pakistani ID Card for the field `Country of Stay`.
- We've removed 2 recognizers: `GermanyDLBack Recognizer` and `SingaporeChangiEmployeeId Recognizer`.


#### Changes to IDBarcodeRecognizer

- For barcodes in countries: Argentina, Colombia, Nigeria, Panama, and South Africa, we now also extract data from the field `Sex` when it's populated with the character "X".


### Improvements

- We've added support for Brazil ID Card when the cardholder's face image is rotated for 90 degrees on the document.
	- We will return face image and document image + data from VIZ part present on the back side.

## 5.15.0

### We support the latest versions of these documents:

#### Europe

* Belgium - Driving License (front only)
* Croatia - ID Card
* France - ID Card
* France - Residence Permit (beta)
* Spain - ID Card
* Switzerland - Residence Permit
* UK - Residence Permit

#### Oceania

* Australia - Northern Territory - Driving License (front only, beta)

#### Middle East and Africa

* UAE - ID Card
* UAE - Resident ID

#### Northern America

* Honduras - ID Card (beta)
* USA - Colorado - ID Card
* USA - Minnesota - Driving License
* USA - Nevada - Driving License
* USA - Oklahoma - Driving License
* USA - Wyoming - Driving License

### Changes to BlinkID(Combined) Recognizer

* No API changes

#### Improvements

* We now support `DataMatch` functionality on single side documents (Passports)
    * We added a special case to support `DataMatch` for UAE ID Card and Resident ID Card documents for the field `personal_id_number`
* We can now extract `additional_personal_id_number` on Ecuador ID Card
* We’ve made improvements for reading NRIC number on Malaysian documents that have an asterisk (\*) character present
* We’ve improved document detection and cropping of the document image

### Changes to IdBarcodeRecognizer

- we've added document type `MB_BARCODE_DOCUMENT_TYPE_ARGENTINA_ALIEN_ID` and added support for parsing Argentina Alien IDs

### Other changes

- We are now requiring NEON+VFPv4 support for `armeabi-v7a` Android devices
    - almost every 32-bit Android device we know of supports that
- We've raised the minimum required version of iOS to 11.0
- We've raised the minimum required version of MacOS to 10.15 (Catalina)
- We've raised the minimum required version of GLIBC on Linux to 2.26
    - we now build the SDK on Amazon Linux 2, instead of CentOS 7. Amazon Linux 2 uses GLIBC 2.26 so the SDK will work on any Linux distribution that uses same or newer version of GLIBC.

## 5.14.0

### Back side support added:
- Thailand - ID Card

### Changes to BlinkID(Combined) Recognizer
- Added new result members - `fathersName` and `mothersName` both in BlinkID and BlinkIDCombined Recognizers, as well as in VIZ result

### Improvements
- We can now extract `fathers_name` and `mothers_name` from Mexico Voter ID Card
- Australian Driving Licenses for New South Wales, Northern Territory, Queensland, Victoria and Western Australia now have the driver license unique card number field extracted as `document_additional_number`

### Changes to BarcodeRecognizer
- We’ve removed support for `aztec` and `dataMatrix` barcode formats from BarcodeRecognizer

### Changes to MRTDRecognizer
- Added `MRTD_TYPE_BORDER_CROSSING_CARD` to MRTD enum

### Bug fixes

- we've fixed the issue affecting returning encoded face and signature images on Android
- we've fixed the crash that could occur if specific image ROI was set for processing

## 5.13.0

### New additions to our supported document list

We’ve added 61 new documents:

#### Europe
- Austria - Paper Passport
- Belarus - Paper Passport
- Belgium - Paper Passport (beta)
- Bulgaria - Paper Passport
- Estonia - Paper Passport
- France - Paper Passport (beta)
- Georgia - Paper Passport (beta)
- Germany - Paper Passport
- Greece - Paper Passport
- Hungary- Paper Passport
- Italy - Paper Passport (beta)
- Kosovo - Paper Passport
- Moldova - Paper Passport (beta)
- Poland - Paper Passport
- Portugal - Paper Passport
- Spain - Paper Passport
- Switzerland - Paper Passport
- UK - Paper Passport

#### Middle East and Africa
- Algeria - Paper Passport (beta)
- Egypt - Paper Passport (beta)
- Eswatini - Paper Passport
- Ghana - Paper Passport
- Iran - Paper Passport (beta)
- Iraq - Paper Passport (beta)
- Israel - Paper Passport (beta)
- Jordan - Paper Passport (beta)
- Kenya - Polycarbonate Passport
- Libya - Polycarbonate Passport (beta)
- Morocco - Paper Passport (beta)
- Nigeria - Paper Passport
- Nigeria - Polycarbonate Passport (beta)
- Qatar - ID Card (front only, beta)
- Saudi Arabia - Paper Passport
- Syria - Paper Passport
- Tanzania - ID Card (beta)
- Tanzania - Voter ID (front only, beta)
- Tunisia - Paper Passport
- Turkey - Paper Passport
- Zimbabwe - Paper Passport

#### Latin America and the Caribbean
- Argentina - Paper Passport
- Brazil - Paper Passport (beta)
- Guatemala - Paper Passport
- Haiti - Paper Passport
- Honduras - Paper Passport (beta)
- Mexico - Paper Passport (beta)
- Mexico - Nayarit - Driving Licence (beta)

#### Asia
- Bangladesh - Paper Passport
- China - Paper Passport (beta)
- India - Paper Passport
- Indonesia - Paper Passport
- Japan - Paper Passport
- Nepal - Paper Passport
- Pakistan - Paper Passport
- Philippines - Paper Passport
- South Korea - Paper Passport (beta)
- Sri Lanka - Paper Passport
- Uzbekistan - Paper Passport

#### Oceania
- Australia - Paper Passport

#### Northern America
- Canada - Paper Passport
- Canada - Weapon Permit (front only, beta)
- USA - Paper Passport (beta)

#### Back side support added:
- Greece - ID Card
- Burkina Faso - ID Card
- Democratic Republic of the Congo - Driving Licence
- Mexico - Veracruz - Driving Licence
- Canada - Citizenship Certificate

#### No longer BETA:
- Belarus - Driving Licence
- UK - Polycarbonate Passport
- Argentina - Alien ID
- Bahamas - Driving Licence
- Mexico - Durango - Driving Licence
- Venezuela - ID Card
- USA - Kansas - ID Card


### Changes to BlinkID(Combined) Recognizer
- We’ve renamed the Swaziland country to Eswatini in results and ClassInfo
- Improved result validation
	- `FieldIdentificationFailed` processing status is used to indicate if unexpected fields are present on the document. Those fields are then deleted from the result
- We are filling out COUNTRY and REGION fields in ClassInfo, without the field TYPE of document, when using BarcodeID mode for scanning documents where the Front side is not supported, and back side results are extracted from AAMVA compliant barcodes
	- This applies only if `ClassInfo` isn’t already prepopulated in some other way and when you’re not in `FullRecognition` mode

#### ImageCapture
- Added support for including or excluding groups of documents supported by the current license with the `captureModeFilter` setting
	- Scanning of documents with AAMVA compliant barcodes with BarcodeID mode
	- Scanning of all licensed documents in BlinkID FullRecognition mode


### Improvements
- We can now extract the date of birth from the document number on the South Korean identity card and from the personal identification number on the driving licence

### Anonymization
- We’ve added anonymization support for new documents:
	- Document number on Germany paper bio-data page Passport
	- Document number on South Korea Identity Card
	- Personal identification number on South Korea driving licence
	- Personal identification number on South Korea paper bio-data page Passport

### New features specific to the C SDK

- We've introduced a new function that lets you create `MBRecognizerImage` directly from a file:
    - Use `recognizerImageLoadFromFile` to create a `MBRecognizerImage` from any JPEG and PNG file
    - You can load another file format using a third-party library and then convert it to `MBRecognizerImage` by calling `recognizerImageCreateFromRawImage`

### Minor API breaking changes

- Functions `recognizerImageCreateFromRawImage` and `recognizerImageSetNewRawBuffer` now use `uint16_t` to specify image dimensions:
    - This used to be `int` for width and height and `size_t` for pixel stride, which was wrong because the SDK doesn't support images larger than `65535x65535` (grayscale) or `16383x16383` (4-channel color). Instead of crashing, the SDK will now produce a compile-time warning when images of this (or greater) size are given to it. If you need support for such images, please let us know.
    - Functions `recognizerImageGetWidth`, `recognizerImageGetHeight` and `recognizerImageGetBytesPerRow` now also return `uint16_t` for the same reason.

### Other features and updates

- We've reduced memory fragmentation when processing video frames.

## 5.12.0

### We've added 15 new documents to our list of supported documents:

#### Europe
- North Macedonia - Polycarbonate Passport

#### Middle East and Africa
- Botswana - ID Card
- Sudan - Polycarbonate Passport

#### Mexico
- Baja California Sur - Driving License (beta)
- Campeche - Driving License (beta)
- Colima - Driving License (beta)

#### Oceania
- Australia - Health Insurance Card (front only, beta)

#### Asia
- Azerbaijan - Polycarbonate Passport (beta)
- Tajikistan - Polycarbonate Passport (beta)

#### Northern America
- Canada - Citizenship Certificate (front only, beta)
- Canada - Ontario - Health Insurance Card (front only)
- Canada - Quebec - Health Insurance Card (front only, beta)
- USA - Military ID Card
- USA - Rhode Island - ID Card
- USA - South Carolina - ID Card

#### Back side support added:
- Ireland - Passport Card
- Mexico - Puebla - Driving License
- Singapore - S PASS

#### No longer BETA:
- Finland - Polycarbonate Passport
- Ireland - Passport Card
- Ireland - Polycarbonate Passport
- Kosovo - Driving License
- Latvia - Polycarbonate Alien Passport
- Latvia - Polycarbonate Passport
- Poland - Polycarbonate Passport
- Cameroon - ID Card
- Ghana - ID Card
- Iraq - ID Card
- Tanzania - Driving License
- Turkey - Polycarbonate Passport
- Uganda - Driving License
- Bolivia - Minors ID
- Chile - Driving License
- Ecuador - Driving License
- Haiti - Driving License
- India - Karnataka - Driving License
- India - Maharashtra - Driving License
- Pakistan - Punjab - Driving License
- USA - Global Entry Card
- USA - New Mexico - ID Card
- USA - Wisconsin - ID Card


### Changes to BlinkID(Combined) Recognizer

- We've added the parameter `maxAllowedMismatchesPerField` to settings. When this is set to a non-zero value, DataMatch will be successful as long as the number of mismatched characters doesn't exceed the specified value.
- We've added the parameter `allowUncertainFrontSideScan` to settings. When this parameter is set to true, the Recognizer will proceed scanning the back side of the document even if the front side scanning result `State` is `MB_RECOGNIZER_RESULT_STATE_UNCERTAIN`.
- We've enabled the return of image and back side data results, even when the `recognitionStatus` is `MB_RECOGNIZER_RESULT_STATE_UNCERTAIN`. Keep in mind that returned images, in this case, might be blurry or low quality.
	- This applies to all image types: full document image, face and signature image.
- We've added two separate fields for the processing status in the Recognizer Result: `frontProcessingStatus` and `backProcessingStatus`. They indicate the status of the last recognition process for each side.

### Improvements

- We added support for the Malaysian NRIC numbers that hold an asterisk (\*) character.
- While using `MB_RECOGNITION_MODE_FULL_RECOGNITION` for scanning unsupported Passports, we are now extracting `MBClassInfo` from MRZ
- Improved quality of fully cropped vertical images
- Better parsing of Bermuda Driving License AAMVA-compliant barcode dates
- Fix for correct calculation of check digit for Saudi Arabia ID Card MRZ
- We are splitting first and last name from the additional name information (e.g., Nom d’ usage, Epouse, Geb. etc.)  into two different results. The additional name info will be a part of the `name_additional_info` field. This applies to the following documents:

	- France
		- ID Card
		- Residence Permit
	- Germany
		- ID Card
	- Luxembourg
		- ID Card
	- Netherlands
		- Driving License
		- Polycarbonate Passport

- We are removing title prefixes (e.g., Mrs., Mr., Ing., etc.) from `full_name`, `first_name` and `last_name` for these documents:
	- Austria
		- Driving License
		- ID Card
	- Czechia
		- Driving License
	- Germany
		- ID Card
	- Thailand
		- ID Card
	- UK
		- Driving License


#### Anonymization

- We've added anonymization for new documents:
	- Document number on Germany Polycarbonate Passport
	- Document number on Hong Kong Polycarbonate Passport
	- Document number and personal ID number on Singapore Polycarbonate Passport


## 5.11.0

### New documents added to BlinkID(Combined)Recognizer:
#### Europe
- Albania - Driver Card (front only)
- Albania - Professional DL (front only)
- Belarus - Driving Licence (front only, beta)
- Belgium - Minors ID (beta)
- Czechia - Residence Permit
- Finland - Alien ID
- Finland - Residence Permit (beta)
- Georgia - Driving Licence (front only)
- Greece - Residence Permit
- Ireland - Passport Card (beta)
- Ireland - Public Services Card (beta)
- Kosovo - Driving Licence (front only, beta)
- Latvia - Alien ID
- Luxembourg - ID Card
- Moldova - ID Card (beta)
- North Macedonia - Driving Licence (front only)
- North Macedonia - ID Card
- Poland - Passport (beta)
- Slovenia - Residence Permit (beta)
- Spain - Alien ID
- UK - Passport (beta)

#### MEA
- Algeria - Driving Licence
- Burkina Faso - ID Card (front only)
- Cameroon - ID Card (beta)
- Democratic Republic Of The Congo - Driving Licence (front only, beta)
- Egypt - Driving Licence (beta)
- Ghana - ID Card (beta)
- Iraq - ID Card (beta)
- Ivory Coast - Driving Licence (front only, beta)
- Ivory Coast - ID Card
- Lebanon - ID Card (beta)
- Morocco - Driving Licence
- Mozambique - Driving Licence (front only, beta)
- Oman - Driving Licence (beta)
- Rwanda - ID Card (front only)
- Senegal - ID Card
- Tanzania - Driving Licence (front only, beta)
- Tunisia - Driving Licence (front only)
- Uganda - Driving Licence (front only, beta)

#### Latin America & the Caribbean
- Argentina - Alien ID (beta)
- Bahamas - ID Card (front only, beta)
- Bolivia - Minors ID (beta)
- Jamaica - Driving Licence
- Mexico - Residence Permit (beta)
- Mexico - Chiapas - Driving Licence (front only)
- Mexico - Coahuila - Driving Licence (beta)
- Mexico - Durango - Driving Licence (front only, beta)
- Mexico - Guerrero-cocula - Driving Licence (beta)
- Mexico - Guerrero-juchitan - Driving Licence (beta)
- Mexico - Guerrero-tepecoacuilco - Driving Licence (front only, beta)
- Mexico - Guerrero-tlacoapa - Driving Licence (front only, beta)
- Mexico - Hidalgo - Driving Licence
- Mexico - Mexico - Driving Licence (beta)
- Mexico - Morelos - Driving Licence (front only)
- Mexico - Oaxaca - Driving Licence
- Mexico - Puebla - Driving Licence (front only, beta)
- Mexico - San Luis Potosi - Driving Licence (front only)
- Mexico - Sinaloa - Driving Licence (front only, beta)
- Mexico - Sonora - Driving Licence (beta)
- Mexico - Tabasco - Driving Licence (beta)
- Mexico - Yucatan - Driving Licence (beta)
- Mexico - Zacatecas - Driving Licence (beta)
- Panama - Temporary Residence Permit (beta)
- Peru - Minors ID (beta)
- Trinidad And Tobago - Driving Licence (front only, beta)
- Trinidad And Tobago - ID Card

#### Oceania
- Australia - South Australia - Proof Of Age Card (front only, beta)

#### Asia
- Armenia - ID Card
- Bangladesh - Driving Licence (beta)
- Cambodia - Driving Licence (front only, beta)
- India - Gujarat - Driving Licence (front only, beta)
- India - Karnataka - Driving Licence (front only, beta)
- India - Kerala - Driving Licence (beta)
- India - Madhya Pradesh - Driving Licence (front only, beta)
- India - Maharashtra - Driving Licence (front only, beta)
- India - Punjab - Driving Licence (front only, beta)
- India - Tamil Nadu - Driving Licence (beta)
- Kyrgyzstan - ID Card
- Malaysia - Mypolis (beta)
- Malaysia - Refugee ID (front only)
- Myanmar - Driving Licence (beta)
- Pakistan - Punjab - Driving Licence (front only, beta)
- Sri Lanka - Driving Licence (front only)
- Thailand - Alien ID (front only)
- Thailand - Driving Licence (beta)
- Uzbekistan - Driving Licence (front only, beta)

#### Northern America
- Canada - Tribal ID (beta)
- Canada - Nova Scotia - ID Card (beta)
- Canada - Saskatchewan - ID Card (beta)
- USA - Border Crossing Card (front only)
- USA - Global Entry Card (beta)
- USA - Nexus Card (beta)
- USA - Veteran ID (front only)
- USA - Work Permit
- USA - Mississippi - ID Card (beta)
- USA - Montana - ID Card
- USA - New Mexico - ID Card (beta)
- USA - Wisconsin - ID Card (beta)

#### Back side support added:
- Hungary - Residence Permit
- Luxembourg - Residence Permit (no longer beta)
- Mauritius - ID Card
- Colombia - Alien ID (no longer beta)
- Mexico - Baja California - Driving Licence
- Mexico - Chihuahua - Driving Licence
- Mexico - Guanajuato - Driving Licence
- Mexico - Michoacan - Driving Licence
- Malaysia - MyKid
- Malaysia - MyPR

#### No longer beta:
- Albania - Passport
- Malta - Residence Permit
- Switzerland - Residence Permit
- Bolivia - Driving Licence
- Chile - Passport
- El Salvador - ID Card
- Peru - ID Card
- Singapore - S Pass (front only)

### Changes to the BlinkId(Combined)Recognizer:
- We enabled retrieving the face image and cropped document image on all documents with AAMVA-compliant barcodes. This behavior activates the `MB_RECOGNITION_MODE_BARCODE_ID` `MBRecognitionMode`. You can opt-out of this behavior by setting `enableBarcodeId` to `MB_FALSE` in the `MBRecognitionModeFilter`.
	- This enables scanning US driver licenses and IDs on which OCR isn't [supported](https://github.com/BlinkID/blinkid-c-sdk/blob/master/BlinkIdRecognizer.md). Use this new recognition mode to extract:
		- Face image from the front side
		- Barcode data from the back side
		- Cropped document images for both sides.
- We've improved data extraction through the MRZ:
	- We now allow standard M/F values for gender on Mexican documents (along with localized H/M values)
- We're now converting dates to the Gregorian calendar:
	- On Taiwan documents with ROC calendar dates
	- On Saudi documents with Islamic calendar dates
- We're now filling all date fields when dates are written in a 'partial' form (year only or month-year only):
	- Date of issue will be converted to the first day of the (first) month
		- E.g. '1999' will be converted to '01.01.1999.'
		- E.g. '03.1999.' will be converted to '01.03.1999.'
	- Date of expiry will be converted to the last day of the (last) month
		- E.g. '1999' will be converted to '31.12.1999.'
		- E.g. '03.1999.' will be converted to '31.03.1999.'

## 5.10.0
​
**Newly supported identity documents**
​
*   Saudi Arabia - DL (front)
*   Saudi Arabia - Resident ID (front)
​
### Changes to the BlinkId(Combined)Recognizer:
​
*   We're now able to extract the additional address on Hungary Address Cards
*   We've improved data extraction through the MRZ:
    *   We now return the document type through `MBClassInfo`, regardless of the `MBRecognitionMode` you're using (`MB_RECOGNITION_MODE_MRZ_ID`, `MB_RECOGNITION_MODE_MRZ_PASSPORT` or `MB_RECOGNITION_MODE_MRZ_VISA`).
    *   This means you can now use `classFilter` to filter these documents by their type.
    *   We now return the document number on Nigeria IDs complete with its check digit.
    *   We now support Italy Residence Permits with a *CR* document code.
*   We've extended the `MBClassInfo` structure with helper methods so you can filter documents by country more easily:
    *   Use `countryName`, `isoNumericCountryCode`, `isoAlpha2CountryCode` and `isoAlpha3CountryCode` to get the full country names or their representative codes defined by [ISO](https://en.wikipedia.org/wiki/List_of_ISO_3166_country_codes).
*   We've extended the `MBBarcodeResult` structure with `extendedElements`
    *   You can find all data from AAMVA-compliant barcodes under their respective [BarcodeElementKey](https://blinkid.github.io/blinkid-c-sdk/_barcode_element_key_8h.html) in the [extendedElements](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_barcode_result.html#ac00661f60071ab1b0d304556c397828d) array
    *   For a full list of keys please see [here](https://blinkid.github.io/blinkid-c-sdk/_barcode_element_key_8h.html#abe14eb9bfca2f891fc0c2c2a8e9a1588)
*   We've added another `MBProcessingStatus` called `MB_PROCESSING_STATUS_AWAITING_OTHER_SIDE`
    *   This status is triggered once BlinkID has finished with the first side of a document and expects the other side, too.
*   We're now able to extract the date of birth from the CURP field on Mexico Voter IDs
*   We've added a new recognition mode for recognizing still images of documents that have already been cropped:
	*   Set the `scanCroppedDocumentImage` to `MB_TRUE` when you're feeding BlinkID images of documents that have already been cropped and don't require detection.
	*   Keep in mind that this setting won't work on document images that haven't been properly cropped.
​
### Changes to the IdBarcodeRecognizer:
​
*   We've extended the results with `extendedElements`
    *   You can find all data from AAMVA-compliant barcodes under their respective [BarcodeElementKey](https://blinkid.github.io/blinkid-c-sdk/_barcode_element_key_8h.html) in the [extendedElements](https://blinkid.github.io/blinkid-c-sdk/struct_m_b_id_barcode_recognizer_result.html#ab27e73c59fd636cb0a89a7ee4d09fb0e) array
    *   For a full list of keys please see [here](https://blinkid.github.io/blinkid-c-sdk/_barcode_element_key_8h.html#abe14eb9bfca2f891fc0c2c2a8e9a1588)
​
### New features
​
- We've added support for ARM-based Macs
    - The MacOS binary is now a fat binary, containing Intel x64 and ARM64 slices
    - The iOS binary is now packaged as a XCFramework containing slices for device (armv7 + arm64), simulator (arm64 + x86_64 + i386) and Mac Catalyst (arm64 + x86_64)
​
### Fixes
​
- We've increased the time before a connection timeout is declared, while obtaining server-side license permission or reporting usage statistics
- We've ensured the `barcodeData` field is filled for `IDBarcodeRecognizer`, `BlinkIdRecognizer` and `BlinkIdCombinedRecognizer`
- We're now correctly initializing the `blurred` field in `MBImageAnalysisResult` (it was always uninitialized)
​
### Minor API changes
​
- We've fixed the naming prefix in `MBBarcodeType`, `MBRecognizerErrorStatus`, `MBMRTDDocumentType`, `MBDataMatch`, `MBRecognizerResultState`, `MBMRTDDocumentType`, `MBRawImageType` and `MBImageOrientation` enums
- We've added the missing `empty` field in `MBDate`, `MBBarcodeResult` and `MBVIZResult`
- We've unified `MBBlinkIdRecognizerResult` and `MBBlinkIdCombinedRecognizerResult`
    - Common fields (contained in both of those structures) are now in the `MBBlinkIdRecognizerCommonResult` structure (field `common`)
    - This helps with keeping BlinkIdRecognizer and BlinkIdCombinedRecognizer APIs in sync

## 5.9.1

- fix implicit resetting of recognizers when using `recognizerRunnerRecognizeFromImage` for still images
    - if the user wants to reset the recognizers, they have to be explicitly reset between recognizing successive images
      by calling `recognizerRunnerReset`

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
