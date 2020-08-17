# Release notes

## 5.7.0

- This is the initial release of the new BlinkID C SDK. The new C SDK is built from the same building blocks as our mobile and web solutions, enabling state of the art identity document scanning through a flexible C API.
- For scanning only the front side of an identity document or any MRTD (including passports and visas), see [BlinkIDRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#blinkidRecognizer).
- For scanning both sides of an identity document as well as any MRTD (including passports and visas), see [BlinkIDCombinedRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#blinkidCombinedRecognizer).
    - A list of all supported documents can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/BlinkIdRecognizer.md).
    - A list of extracted fields on the supported documents can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/BlinkIdDocumentFields.md).
- For scanning barcodes on identity documents and extracting parsed barcode data, see [IdBarcodeRecognizer](https://github.com/BlinkID/blinkid-c-sdk/blob/master/README.md#idBarcodeRecognizer).
    - A list of supported IDs with barcodes can be found [here](https://github.com/BlinkID/blinkid-c-sdk/blob/master/IdBarcodeRecognizer.md).
