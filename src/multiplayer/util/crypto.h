#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <string_view>

enum class CryptoError : uint8_t {
	CE_NO_ERROR,
	CE_INIT,
	CE_PWHASH,
	CE_GENERICHASH,
	CE_PAD,
	CE_COPY_KEY,
	CE_ENCRYPT,
	CE_CIPHER_DATA_INVALID,
	CE_DECRYPT,
	CE_UNPAD,
};

std::string CryptoErrString(CryptoError err);

CryptoError CryptoGetPasswordBase64Hash(std::string_view password, std::string& base64_hash);

CryptoError CryptoEncryptText(std::string_view password, std::string_view plain, std::vector<char>& cipher_data);
CryptoError CryptoDecryptText(std::string_view password, const std::vector<char>& cipher_data, std::string& plain);
