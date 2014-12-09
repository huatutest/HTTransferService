#pragma once

//This error code is used for DGEncryptPlus

#define DG_ERROR_DOMAIN_NOT_CARE	0x0000F000
#define DG_ERROR_DOMAIN_FATAL		0x0000E000
#define DG_ERROR_DOMAIN_IMPOSSIBLE	0x0000D000
#define DG_ERROR_DOMAIN_IMPORTANT	0x0000C000

#define DG_ERROR_DGEP_START_POSITION	0x00000E00
typedef enum INTER_ERROR
{
	ERROR_DGEP_AES_BUFF_NOT_ENOUGH_FOR_FILE_OWNER_IN_GET_FILE_OWNER = 0x0000FE01,
	ERROR_DGEP_DG_CREATE_FILE_IN_IS_CRYPTED_FILE_FAILED = 0x0000FE02,
	ERROR_DGEP_DGP_CREATE_FILE_IN_IS_CRYPTED_FILE_FAILED = 0x0000FE03,
	ERROR_DGEP_CW_GUID_IS_EMPTY_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000FE04,
	ERROR_DGEP_CW_GUID_IS_EMPTY_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000FE05,
	ERROR_DGEP_CW_GUID_IS_EMPTY_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000FE06,




	ERROR_DGEP_CW_AES_TYPE_UNKNOWN_IN_GET_FILE_CRYPT_INFO_INTERNAL = 0x0000EE01,
	ERROR_DGEP_CW_DG_TYPE_UNKNOWN_IN_GET_FILE_CRYPT_INFO_INTERNAL = 0x0000EE02,
	ERROR_DGEP_CW_DGP_TYPE_UNKNOWN_IN_GET_FILE_CRYPT_INFO_INTERNAL = 0x0000EE03,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_IS_CRYPTED_FILE_SIMPLE_FAILED = 0x0000EE04,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_IS_CRYPTED_FILE_FAILED = 0x0000EE05,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_IS_CRYPTED_FILE_FULL_FAILED = 0x0000EE06,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_CRYPTED_TYPE_SIMPLE_FAILED = 0x0000EE07,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_CRYPT_INFO_SIMPLE_FAILED = 0x0000EE08,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_DECRYPT_FILE_SIMPLE_FAILED = 0x0000EE09,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_MODIFY_FILE_KEY_SIMPLE_FAILED = 0x0000EE0A,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_LEVEL_SIMPLE_FAILED = 0x0000EE0B,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_LEVEL_SIMPLE_FAILED = 0x0000EE0C,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000EE0D,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000EE0E,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_CLEAR_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000EE0F,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_GUID_SIMPLE_FAILED = 0x0000EE10,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000EE11,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000EE12,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000EE13,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_OWNER_SIMPLE_FAILED = 0x0000EE14,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_OWNER_SIMPLE_FAILED = 0x0000EE15,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000EE16,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000EE17,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000EE18,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000EE19,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000EE1A,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000EE1B,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000EE1C,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000EE1D,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_TIME_SIMPLE_FAILED = 0x0000EE1E,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_TIME_SIMPLE_FAILED = 0x0000EE1F,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_SET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000EE20,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_GET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000EE21,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_INTERNAL_IN_DECRYPT_FILE_WITH_TAGET_SIMPLE_FAILED = 0x0000EE22,




	ERROR_DGEP_DG_GET_FILE_SIZE_EX_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE01,
	ERROR_DGEP_DG_CREATE_FILE_MAPPING_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE02,
	ERROR_DGEP_DG_MAP_VIEW_OF_FILE_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE03,
	ERROR_DGEP_DG_CREATE_FILE_MAPPING_IN_SET_FILE_HEAD_FAILED = 0x0000DE04,
	ERROR_DGEP_DG_MAP_VIEW_OF_FILE_IN_SET_FILE_HEAD_FAILED = 0x0000DE05,
	ERROR_DGEP_DGP_CREATE_FILE_MAPPING_IN_SET_FILE_HEAD_FAILED = 0x0000DE06,
	ERROR_DGEP_DGP_MAP_VIEW_OF_FILE_IN_SET_FILE_HEAD_FAILED = 0x0000DE07,
	ERROR_DGEP_DGP_GET_FILE_SIZE_EX_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE08,
	ERROR_DGEP_DGP_CREATE_FILE_MAPPING_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE09,
	ERROR_DGEP_DGP_MAP_VIEW_OF_FILE_IN_IS_CRYPTED_FILE_FAILED = 0x0000DE0A,
	ERROR_DGEP_DG_GET_FILE_TIME_IN_DECRYPT_FILE_FAILED = 0x0000DE0B,
	ERROR_DGEP_DG_SET_FILE_TIME_IN_DECRYPT_FILE_FAILED = 0x0000DE0C,
	ERROR_DGEP_DG_GET_FILE_SIZE_IN_DECRYPT_FILE_FAILED = 0x0000DE0D,
	ERROR_DGEP_DG_CREATE_FILE_MAPPING_IN_DECRYPT_FILE_FAILED = 0x0000DE0E,
	ERROR_DGEP_DG_DECRYPT_FILE_DG_ONE_IN_DECRYPT_FILE_FAILED = 0x0000DE0F,
	ERROR_DGEP_DG_DECRYPT_FILE_DG_THREE_IN_DECRYPT_FILE_FAILED = 0x0000DE10,
	ERROR_DGEP_DG_DECRYPT_FILE_DG_FOUR_IN_DECRYPT_FILE_FAILED = 0x0000DE11,
	ERROR_DGEP_DG_SET_FILE_POINTER_EX_IN_DECRYPT_FILE_FAILED = 0x0000DE12,
	ERROR_DGEP_DG_SET_END_OF_FILE_IN_DECRYPT_FILE_FAILED = 0x0000DE13,
	ERROR_DGEP_DGP_GET_FILE_TIME_IN_DECRYPT_FILE_FAILED = 0x0000DE14,
	ERROR_DGEP_DGP_GET_FILE_SIZE_IN_DECRYPT_FILE_FAILED = 0x0000DE15,
	ERROR_DGEP_DGP_CREATE_FILE_MAPPING_IN_DECRYPT_FILE_FAILED = 0x0000DE16,
	ERROR_DGEP_DGP_DECRYPT_FILE_DG_FIVE_IN_DECRYPT_FILE_FAILED = 0x0000DE17,
	ERROR_DGEP_DGP_SET_FILE_POINTER_EX_IN_DECRYPT_FILE_FAILED = 0x0000DE18,
	ERROR_DGEP_DGP_SET_END_OF_FILE_IN_DECRYPT_FILE_FAILED = 0x0000DE19,
	ERROR_DGEP_DGP_SET_FILE_TIME_IN_DECRYPT_FILE_FAILED = 0x0000DE1A,
	ERROR_DGEP_DGP_ENCRYPT_FILE_IN_ENCRYPT_FILE_FAILED = 0x0000DE1B,
	ERROR_DGEP_DGP_GET_FILE_TIME_IN_ENCRYPT_FILE_FAILED = 0x0000DE1C,
	ERROR_DGEP_DGP_GET_FILE_SIZE_IN_ENCRYPT_FILE_FAILED = 0x0000DE1D,
	ERROR_DGEP_DGP_CREATE_FILE_MAPPING_IN_ENCRYPT_FILE_FAILED = 0x0000DE1E,
	ERROR_DGEP_DGP_SET_FILE_TIME_IN_ENCRYPT_FILE_FAILED = 0x0000DE1F,
	ERROR_DGEP_DGP_ENCRYPT_FILE_DG_FIVE_IN_ENCRYPT_FILE_FAILED = 0x0000DE20,





	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_CRYPT_INFO_SIMPLE = 0x0000CE01,
	ERROR_DGEP_CW_BUFFER_NOT_ENOUGH_FOR_AES_INFO_IN_GET_FILE_CRYPT_INFO_SIMPLE = 0x0000CE02,
	ERROR_DGEP_CW_BUFFER_NOT_ENOUGH_FOR_DG_INFO_IN_GET_FILE_CRYPT_INFO_SIMPLE = 0x0000CE03,
	ERROR_DGEP_CW_BUFFER_NOT_ENOUGH_FOR_DGP_INFO_IN_GET_FILE_CRYPT_INFO_SIMPLE = 0x0000CE04,
	ERROR_DGEP_CW_GET_FILE_CRYPTED_TYPE_IN_GET_FILE_CRYPTED_TYPE_FAILED = 0x0000CE05,
	ERROR_DGEP_CW_GET_FILE_CRYPTED_TYPE_IN_GET_FILE_CRYPTED_TYPE_FULL_FAILED = 0x0000CE06,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_IN_GET_FILE_CRYPT_INFO_FAILED = 0x0000CE07,
	ERROR_DGEP_CW_GET_FILE_CRYPT_INFO_IN_GET_FILE_CRYPT_INFO_FULL_FAILED = 0x0000CE08,
	ERROR_DGEP_CW_CRYPT_FILE_IN_CRYPT_FILE_FAILED = 0x0000CE09,
	ERROR_DGEP_CW_DECRYPT_FILE_IN_DECRYPT_FILE_FULL_FAILED = 0x0000CE0A,
	ERROR_DGEP_CW_MODIFY_FILE_KEY_IN_MODIFY_FILE_KEY_FAILED = 0x0000CE0B,
	ERROR_DGEP_CW_MODIFY_FILE_KEY_IN_MODIFY_FILE_KEY_FULL_FAILED = 0x0000CE0C,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_DECRYPT_FILE_SIMPLE = 0x0000CE0D,
	ERROR_DGEP_CW_AES_DECRYPT_FILE_IN_DECRYPT_FILE_SIMPLE_FAILED = 0x0000CE0E,
	ERROR_DGEP_CW_DG_DECRYPT_FILE_IN_DECRYPT_FILE_SIMPLE_FAILED = 0x0000CE0F,
	ERROR_DGEP_CW_DGP_DECRYPT_FILE_IN_DECRYPT_FILE_SIMPLE_FAILED = 0x0000CE10,
	ERROR_DGEP_CW_SET_FILE_LEVEL_IN_SET_FILE_LEVEL_FAILED = 0x0000CE11,
	ERROR_DGEP_CW_SET_FILE_LEVEL_IN_SET_FILE_LEVEL_FULL_FAILED = 0x0000CE12,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE13,
	ERROR_DGEP_CW_AES_SET_FILE_LEVEL_IN_SET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE14,
	ERROR_DGEP_CW_DG_SET_FILE_LEVEL_IN_SET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE15,
	ERROR_DGEP_CW_DGP_SET_FILE_LEVEL_IN_SET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE16,
	ERROR_DGEP_CW_GET_FILE_LEVEL_IN_GET_FILE_LEVEL_FAILED = 0x0000CE17,
	ERROR_DGEP_CW_GET_FILE_LEVEL_IN_GET_FILE_LEVEL_FULL_FAILED = 0x0000CE18,
	ERROR_DGEP_CW_DGP_ENCRYPT_FILE_IN_ENCRYPT_FILE_SIMPLE_FAILED = 0x0000CE19,
	ERROR_DGEP_CW_DGP_ENCRYPT_FILE_IN_ENCRYPT_FILE_FAILED = 0x0000CE1A,
	ERROR_DGEP_CW_DGP_ENCRYPT_FILE_IN_ENCRYPT_FILE_FULL_FAILED = 0x0000CE1B,
	ERROR_DGEP_CW_ENCRYPT_FILE_IN_ENCRYPT_FILE_SIMPLE_FAILED = 0x0000CE1C,
	ERROR_DGEP_CW_ENCRYPT_FILE_IN_ENCRYPT_FILE_FAILED = 0x0000CE1D,
	ERROR_DGEP_CW_ENCRYPT_FILE_IN_ENCRYPT_FILE_FULL_FAILED = 0x0000CE1E,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_MODIFY_FILE_KEY_SIMPLE_FAILED = 0x0000CE1F,
	ERROR_DGEP_CW_AES_MODIFY_FILE_KEY_IN_MODIFY_FILE_KEY_SIMPLE_FAILED = 0x0000CE20,
	ERROR_DGEP_CW_DG_MODIFY_FILE_KEY_IN_MODIFY_FILE_KEY_SIMPLE_FAILED = 0x0000CE21,
	ERROR_DGEP_CW_DGP_MODIFY_FILE_KEY_IN_MODIFY_FILE_KEY_SIMPLE_FAILED = 0x0000CE22,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE23,
	ERROR_DGEP_CW_AES_GET_FILE_LEVEL_IN_GET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE24,
	ERROR_DGEP_CW_DG_GET_FILE_LEVEL_IN_GET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE25,
	ERROR_DGEP_CW_DGP_GET_FILE_LEVEL_IN_GET_FILE_LEVEL_SIMPLE_FAILED = 0x0000CE26,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE27,
	ERROR_DGEP_CW_AES_SET_FILE_LIMIT_TIME_IN_SET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE28,
	ERROR_DGEP_CW_DG_SET_FILE_LIMIT_TIME_IN_SET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE29,
	ERROR_DGEP_CW_DGP_SET_FILE_LIMIT_TIME_IN_SET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE2A,
	ERROR_DGEP_CW_SET_FILE_LIMIT_TIME_IN_SET_FILE_LIMIT_TIME_FAILED = 0x0000CE2B,
	ERROR_DGEP_CW_SET_FILE_LIMIT_TIME_IN_SET_FILE_LIMIT_TIME_FULL_FAILED = 0x0000CE2C,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE2D,
	ERROR_DGEP_CW_AES_GET_FILE_LIMIT_TIME_IN_GET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE2E,
	ERROR_DGEP_CW_DG_GET_FILE_LIMIT_TIME_IN_GET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE2F,
	ERROR_DGEP_CW_DGP_GET_FILE_LIMIT_TIME_IN_GET_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE30,
	ERROR_DGEP_CW_GET_FILE_LIMIT_TIME_IN_GET_FILE_LIMIT_TIME_FAILED = 0x0000CE31,
	ERROR_DGEP_CW_GET_FILE_LIMIT_TIME_IN_GET_FILE_LIMIT_TIME_FULL_FAILED = 0x0000CE32,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_CLEAR_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE33,
	ERROR_DGEP_CW_AES_CLEAR_FILE_LIMIT_TIME_IN_CLEAR_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE34,
	ERROR_DGEP_CW_DG_CLEAR_FILE_LIMIT_TIME_IN_CLEAR_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE35,
	ERROR_DGEP_CW_DGP_CLEAR_FILE_LIMIT_TIME_IN_CLEAR_FILE_LIMIT_TIME_SIMPLE_FAILED = 0x0000CE36,
	ERROR_DGEP_CW_CLEAR_FILE_LIMIT_TIME_IN_CLEAR_FILE_LIMIT_TIME_FAILED = 0x0000CE37,
	ERROR_DGEP_CW_CLEAR_FILE_LIMIT_TIME_IN_CLEAR_FILE_LIMIT_TIME_FULL_FAILED = 0x0000CE38,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_GUID_SIMPLE_FAILED = 0x0000CE39,
	ERROR_DGEP_CW_AES_SET_FILE_GUID_IN_SET_FILE_GUID_SIMPLE_FAILED = 0x0000CE3A,
	ERROR_DGEP_CW_DG_SET_FILE_GUID_IN_SET_FILE_GUID_SIMPLE_FAILED = 0x0000CE3B,
	ERROR_DGEP_CW_DGP_SET_FILE_GUID_IN_SET_FILE_GUID_SIMPLE_FAILED = 0x0000CE3C,
	ERROR_DGEP_CW_SET_FILE_GUID_IN_SET_FILE_GUID_FAILED = 0x0000CE34,
	ERROR_DGEP_CW_SET_FILE_GUID_IN_SET_FILE_GUID_FULL_FAILED = 0x0000CE35,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000CE36,
	ERROR_DGEP_CW_AES_GET_FILE_GUID_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000CE37,
	ERROR_DGEP_CW_DG_GET_FILE_GUID_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000CE38,
	ERROR_DGEP_CW_DGP_GET_FILE_GUID_IN_GET_FILE_GUID_SIMPLE_FAILED = 0x0000CE39,
	ERROR_DGEP_CW_GET_FILE_GUID_IN_GET_FILE_GUID_FAILED = 0x0000CE3A,
	ERROR_DGEP_CW_GET_FILE_GUID_IN_GET_FILE_GUID_FULL_FAILED = 0x0000CE3B,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE3C,
	ERROR_DGEP_CW_AES_SET_FILE_OUTSIDE_GUID_IN_SET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE3D,
	ERROR_DGEP_CW_DG_SET_FILE_OUTSIDE_GUID_IN_SET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE3E,
	ERROR_DGEP_CW_DGP_SET_FILE_OUTSIDE_GUID_IN_SET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE3F,
	ERROR_DGEP_CW_SET_FILE_OUTSIDE_GUID_IN_SET_FILE_OUTSIDE_GUID_FAILED = 0x0000CE40,
	ERROR_DGEP_CW_SET_FILE_OUTSIDE_GUID_IN_SET_FILE_OUTSIDE_GUID_FULL_FAILED = 0x0000CE41,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE42,
	ERROR_DGEP_CW_AES_GET_FILE_OUTSIDE_GUID_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE43,
	ERROR_DGEP_CW_DG_GET_FILE_OUTSIDE_GUID_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE44,
	ERROR_DGEP_CW_DGP_GET_FILE_OUTSIDE_GUID_IN_GET_FILE_OUTSIDE_GUID_SIMPLE_FAILED = 0x0000CE45,
	ERROR_DGEP_CW_GET_FILE_OUTSIDE_GUID_IN_GET_FILE_OUTSIDE_GUID_FAILED = 0x0000CE46,
	ERROR_DGEP_CW_GET_FILE_OUTSIDE_GUID_IN_GET_FILE_OUTSIDE_GUID_FULL_FAILED = 0x0000CE47,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE48,
	ERROR_DGEP_CW_AES_SET_FILE_OWNER_IN_SET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE49,
	ERROR_DGEP_CW_DG_SET_FILE_OWNER_IN_SET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE4A,
	ERROR_DGEP_CW_DGP_SET_FILE_OWNER_IN_SET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE4B,
	ERROR_DGEP_CW_SET_FILE_OWNER_IN_SET_FILE_OWNER_FAILED = 0x0000CE4C,
	ERROR_DGEP_CW_SET_FILE_OWNER_IN_SET_FILE_OWNER_FULL_FAILED = 0x0000CE4D,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE4E,
	ERROR_DGEP_CW_AES_GET_FILE_OWNER_IN_GET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE4F,
	ERROR_DGEP_CW_DG_GET_FILE_OWNER_IN_GET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE50,
	ERROR_DGEP_CW_DGP_GET_FILE_OWNER_IN_GET_FILE_OWNER_SIMPLE_FAILED = 0x0000CE51,
	ERROR_DGEP_CW_GET_FILE_OWNER_IN_GET_FILE_OWNER_FAILED = 0x0000CE52,
	ERROR_DGEP_CW_GET_FILE_OWNER_IN_GET_FILE_OWNER_FULL_FAILED = 0x0000CE53,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE54,
	ERROR_DGEP_CW_AES_SET_FILE_PERMISSION_IN_SET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE55,
	ERROR_DGEP_CW_DG_SET_FILE_PERMISSION_IN_SET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE56,
	ERROR_DGEP_CW_DGP_SET_FILE_PERMISSION_IN_SET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE57,
	ERROR_DGEP_CW_SET_FILE_PERMISSION_IN_SET_FILE_PERMISSION_FAILED = 0x0000CE58,
	ERROR_DGEP_CW_SET_FILE_PERMISSION_IN_SET_FILE_PERMISSION_FULL_FAILED = 0x0000CE59,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE5A,
	ERROR_DGEP_CW_AES_GET_FILE_PERMISSION_IN_GET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE5B,
	ERROR_DGEP_CW_DG_GET_FILE_PERMISSION_IN_GET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE5C,
	ERROR_DGEP_CW_DGP_GET_FILE_PERMISSION_IN_GET_FILE_PERMISSION_SIMPLE_FAILED = 0x0000CE5D,
	ERROR_DGEP_CW_GET_FILE_PERMISSION_IN_GET_FILE_PERMISSION_FAILED = 0x0000CE5E,
	ERROR_DGEP_CW_GET_FILE_PERMISSION_IN_GET_FILE_PERMISSION_FULL_FAILED = 0x0000CE5F,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE60,
	ERROR_DGEP_CW_AES_SET_FILE_AUTHORIZE_GUID_IN_SET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE61,
	ERROR_DGEP_CW_DG_SET_FILE_AUTHORIZE_GUID_IN_SET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE62,
	ERROR_DGEP_CW_DGP_SET_FILE_AUTHORIZE_GUID_IN_SET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE63,
	ERROR_DGEP_CW_SET_FILE_AUTHORIZE_GUID_IN_SET_FILE_AUTHORIZE_GUID_FAILED = 0x0000CE64,
	ERROR_DGEP_CW_SET_FILE_AUTHORIZE_GUID_IN_SET_FILE_AUTHORIZE_GUID_FULL_FAILED = 0x0000CE65,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE66,
	ERROR_DGEP_CW_AES_GET_FILE_AUTHORIZE_GUID_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE67,
	ERROR_DGEP_CW_DG_GET_FILE_AUTHORIZE_GUID_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE68,
	ERROR_DGEP_CW_DGP_GET_FILE_AUTHORIZE_GUID_IN_GET_FILE_AUTHORIZE_GUID_SIMPLE_FAILED = 0x0000CE69,
	ERROR_DGEP_CW_GET_FILE_AUTHORIZE_GUID_IN_GET_FILE_AUTHORIZE_GUID_FAILED = 0x0000CE6A,
	ERROR_DGEP_CW_GET_FILE_AUTHORIZE_GUID_IN_GET_FILE_AUTHORIZE_GUID_FULL_FAILED = 0x0000CE6B,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE6C,
	ERROR_DGEP_CW_AES_SET_FILE_LOG_INFO_IN_SET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE6D,
	ERROR_DGEP_CW_DG_SET_FILE_LOG_INFO_IN_SET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE6E,
	ERROR_DGEP_CW_DGP_SET_FILE_LOG_INFO_IN_SET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE6F,
	ERROR_DGEP_CW_SET_FILE_LOG_INFO_IN_SET_FILE_LOG_INFO_FAILED = 0x0000CE70,
	ERROR_DGEP_CW_SET_FILE_LOG_INFO_IN_SET_FILE_LOG_INFO_FULL_FAILED = 0x0000CE71,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE72,
	ERROR_DGEP_CW_AES_GET_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE73,
	ERROR_DGEP_CW_DG_GET_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE74,
	ERROR_DGEP_CW_DGP_GET_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO_SIMPLE_FAILED = 0x0000CE75,
	ERROR_DGEP_CW_GET_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO_FAILED = 0x0000CE76,
	ERROR_DGEP_CW_GET_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO_FULL_FAILED = 0x0000CE77,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE78,
	ERROR_DGEP_CW_AES_SET_FILE_OWNER_NAME_IN_SET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE79,
	ERROR_DGEP_CW_DG_SET_FILE_OWNER_NAME_IN_SET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE7A,
	ERROR_DGEP_CW_DGP_SET_FILE_OWNER_NAME_IN_SET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE7B,
	ERROR_DGEP_CW_SET_FILE_OWNER_NAME_IN_SET_FILE_OWNER_NAME_FAILED = 0x0000CE7C,
	ERROR_DGEP_CW_SET_FILE_OWNER_NAME_IN_SET_FILE_OWNER_NAME_FULL_FAILED = 0x0000CE7D,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE7E,
	ERROR_DGEP_CW_AES_GET_FILE_OWNER_NAME_IN_GET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE7F,
	ERROR_DGEP_CW_DG_GET_FILE_OWNER_NAME_IN_GET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE80,
	ERROR_DGEP_CW_DGP_GET_FILE_OWNER_NAME_IN_GET_FILE_OWNER_NAME_SIMPLE_FAILED = 0x0000CE81,
	ERROR_DGEP_CW_GET_FILE_OWNER_NAME_IN_GET_FILE_OWNER_NAME_FAILED = 0x0000CE82,
	ERROR_DGEP_CW_GET_FILE_OWNER_NAME_IN_GET_FILE_OWNER_NAME_FULL_FAILED = 0x0000CE83,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_TIME_SIMPLE_FAILED = 0x0000CE84,
	ERROR_DGEP_CW_AES_SET_FILE_TIME_IN_SET_FILE_TIME_SIMPLE_FAILED = 0x0000CE85,
	ERROR_DGEP_CW_DG_SET_FILE_TIME_IN_SET_FILE_TIME_SIMPLE_FAILED = 0x0000CE86,
	ERROR_DGEP_CW_DGP_SET_FILE_TIME_IN_SET_FILE_TIME_SIMPLE_FAILED = 0x0000CE87,
	ERROR_DGEP_CW_SET_FILE_TIME_IN_SET_FILE_TIME_FAILED = 0x0000CE88,
	ERROR_DGEP_CW_SET_FILE_TIME_IN_SET_FILE_TIME_FULL_FAILED = 0x0000CE89,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_TIME_SIMPLE_FAILED = 0x0000CE8A,
	ERROR_DGEP_CW_AES_GET_FILE_TIME_IN_GET_FILE_TIME_SIMPLE_FAILED = 0x0000CE8B,
	ERROR_DGEP_CW_DG_GET_FILE_TIME_IN_GET_FILE_TIME_SIMPLE_FAILED = 0x0000CE8C,
	ERROR_DGEP_CW_DGP_GET_FILE_TIME_IN_GET_FILE_TIME_SIMPLE_FAILED = 0x0000CE8D,
	ERROR_DGEP_CW_GET_FILE_TIME_IN_GET_FILE_TIME_FAILED = 0x0000CE8E,
	ERROR_DGEP_CW_GET_FILE_TIME_IN_GET_FILE_TIME_FULL_FAILED = 0x0000CE8F,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_SET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE90,
	ERROR_DGEP_CW_AES_SET_FILE_EXPIRE_TIME_IN_SET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE91,
	ERROR_DGEP_CW_DG_SET_FILE_EXPIRE_TIME_IN_SET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE92,
	ERROR_DGEP_CW_DGP_SET_FILE_EXPIRE_TIME_IN_SET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE93,
	ERROR_DGEP_CW_SET_FILE_EXPIRE_TIME_IN_SET_FILE_EXPIRE_TIME_FAILED = 0x0000CE94,
	ERROR_DGEP_CW_SET_FILE_EXPIRE_TIME_IN_SET_FILE_EXPIRE_TIME_FULL_FAILED = 0x0000CE95,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_GET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE96,
	ERROR_DGEP_CW_AES_GET_FILE_EXPIRE_TIME_IN_GET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE97,
	ERROR_DGEP_CW_DG_GET_FILE_EXPIRE_TIME_IN_GET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE98,
	ERROR_DGEP_CW_DGP_GET_FILE_EXPIRE_TIME_IN_GET_FILE_EXPIRE_TIME_SIMPLE_FAILED = 0x0000CE99,
	ERROR_DGEP_CW_GET_FILE_EXPIRE_TIME_IN_GET_FILE_EXPIRE_TIME_FAILED = 0x0000CE9A,
	ERROR_DGEP_CW_GET_FILE_EXPIRE_TIME_IN_GET_FILE_EXPIRE_TIME_FULL_FAILED = 0x0000CE9B,
	ERROR_DGEP_CW_FILE_TYPE_NORMAL_IN_DECRYPT_FILE_WITH_TAGET_SIMPLE = 0x0000CE9C,
	ERROR_DGEP_CW_AES_DECRYPT_FILE_WITH_TAGET_IN_DECRYPT_FILE_WITH_TAGET_SIMPLE_FAILED = 0x0000CE9D,
	ERROR_DGEP_CW_DG_DECRYPT_FILE_WITH_TAGET_IN_DECRYPT_FILE_WITH_TAGET_SIMPLE_FAILED = 0x0000CE9E,
	ERROR_DGEP_CW_DGP_DECRYPT_FILE_WITH_TAGET_IN_DECRYPT_FILE_WITH_TAGET_SIMPLE_FAILED = 0x0000CE9F,
	ERROR_DGEP_CW_DECRYPT_FILE_WITH_TAGET_IN_DECRYPT_FILE_WITH_TAGET_FAILED = 0x0000CEA0,
	ERROR_DGEP_CW_DECRYPT_FILE_WITH_TAGET_IN_DECRYPT_FILE_WITH_TAGET_FULL_FAILED = 0x0000CEA1,
	ERROR_DGEP_AES_DECRYPT_FILE_OPERATION_NOT_SUPPORT = 0x0000CEA2,
	ERROR_DGEP_AES_DECRYPT_FILE_IN_DECRYPT_FILE_WITH_TARGET_FAILED = 0x0000CEA3,
	ERROR_DGEP_AES_ENCRYPT_FILE_OPERATION_NOT_SUPPORT = 0x0000CEA4,
	ERROR_DGEP_AES_MODIFY_FILE_KEY_OPERATION_NOT_SUPPORT = 0x0000CEA5,
	ERROR_DGEP_AES_SET_FILE_LEVEL_OPERATION_NOT_SUPPORT = 0x0000CEA6,
	ERROR_DGEP_AES_GET_FILE_LEVEL_OPERATION_NOT_SUPPORT = 0x0000CEA7,
	ERROR_DGEP_AES_SET_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEA8,
	ERROR_DGEP_AES_GET_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEA9,
	ERROR_DGEP_AES_CLEAR_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEAA,
	ERROR_DGEP_AES_STRING_FROM_GUID2_IN_SET_FILE_GUID_FAILED = 0x0000CEAB,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_GUID_FAILED = 0x0000CEAC,
	ERROR_DGEP_AES_CLSID_FROM_STRING_IN_GET_FILE_GUID_FAILED = 0x0000CEAD,
	ERROR_DGEP_AES_SET_FILE_OUTSIDE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEAE,
	ERROR_DGEP_AES_GET_FILE_OUTSIDE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEAF,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_OWNER_FAILED = 0x0000CEB0,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_PERMISSION_FAILED = 0x0000CEB1,
	ERROR_DGEP_AES_SET_FILE_AUTHORIZE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEB2,
	ERROR_DGEP_AES_GET_FILE_AUTHORIZE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEB3,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_LOG_INFO_FAILED = 0x0000CEB4,
	ERROR_DGEP_AES_BUFF_NOT_ENOUGH_FOR_FILE_LOG_INFO_IN_GET_FILE_LOG_INFO = 0x0000CEB5,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_OWNER_NAME_FAILED = 0x0000CEB6,
	ERROR_DGEP_AES_BUFF_NOT_ENOUGH_FOR_FILE_OWNER_NAME_IN_GET_FILE_OWNER = 0x0000CEB7,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_TIME_FAILED = 0x0000CEB8,
	ERROR_DGEP_AES_WRITE_FILE_HEADER_IN_SET_FILE_EXPIRE_TIME_FAILED = 0x0000CEB9,
	ERROR_DGEP_DG_DECRYPT_FILE_WITH_TARGET_OPERATION_NOT_SUPPORT = 0x0000CEBA,
	ERROR_DGEP_DG_SET_FILE_OWNER_OPERATION_NOT_SUPPORT = 0x0000CEBB,
	ERROR_DGEP_DG_GET_FILE_OWNER_OPERATION_NOT_SUPPORT = 0x0000CEBC,
	ERROR_DGEP_DG_SET_FILE_PERMISSION_OPERATION_NOT_SUPPORT = 0x0000CEBD,
	ERROR_DGEP_DG_GET_FILE_PERMISSION_OPERATION_NOT_SUPPORT = 0x0000CEBE,
	ERROR_DGEP_DG_SET_FILE_AUTHORIZE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEBF,
	ERROR_DGEP_DG_GET_FILE_AUTHORIZE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEC0,
	ERROR_DGEP_DG_SET_FILE_LOG_INFO_OPERATION_NOT_SUPPORT = 0x0000CEC1,
	ERROR_DGEP_DG_GET_FILE_LOG_INFO_OPERATION_NOT_SUPPORT = 0x0000CEC2,
	ERROR_DGEP_DG_SET_FILE_OWNER_NAME_OPERATION_NOT_SUPPORT = 0x0000CEC3,
	ERROR_DGEP_DG_GET_FILE_OWNER_NAME_OPERATION_NOT_SUPPORT = 0x0000CEC4,
	ERROR_DGEP_DG_SET_FILE_TIME_OPERATION_NOT_SUPPORT = 0x0000CEC5,
	ERROR_DGEP_DG_GET_FILE_TIME_OPERATION_NOT_SUPPORT = 0x0000CEC6,
	ERROR_DGEP_DG_SET_FILE_EXPIRE_TIME_OPERATION_NOT_SUPPORT = 0x0000CEC7,
	ERROR_DGEP_DG_GET_FILE_EXPIRE_TIME_OPERATION_NOT_SUPPORT = 0x0000CEC8,
	ERROR_DGEP_DG_ENCRYPT_FILE_OPERATION_NOT_SUPPORT = 0x0000CEC9,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_SET_FILE_LIMIT_TIME_FAILED = 0x0000CECA,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_SET_FILE_LEVEL = 0x0000CECB,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_SET_FILE_LEVEL_FAILED = 0x0000CECC,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_GET_FILE_LEVEL = 0x0000CECD,
	ERROR_DGEP_DG_VERSION_THREE_LEVEL_CHECK_CODE_NOT_CONSISTENT_IN_GET_FILE_LEVEL = 0x0000CECE,
	ERROR_DGEP_DG_VERSION_FOUR_LEVEL_CHECK_CODE_NOT_CONSISTENT_IN_GET_FILE_LEVEL = 0x0000CECF,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_SET_FILE_LIMIT_TIME = 0x0000CED0,
	ERROR_DGEP_DGP_SET_FILE_OWNER_NAME_OPERATION_NOT_SUPPORT = 0x0000CED1,
	ERROR_DGEP_DGP_GET_FILE_OWNER_NAME_OPERATION_NOT_SUPPORT = 0x0000CED2,
	ERROR_DGEP_DGP_SET_FILE_TIME_OPERATION_NOT_SUPPORT = 0x0000CED3,
	ERROR_DGEP_DGP_GET_FILE_TIME_OPERATION_NOT_SUPPORT = 0x0000CED4,
	ERROR_DGEP_DGP_SET_FILE_EXPIRE_TIME_OPERATION_NOT_SUPPORT = 0x0000CED5,
	ERROR_DGEP_DGP_GET_FILE_EXPIRE_TIME_OPERATION_NOT_SUPPORT = 0x0000CED6,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_GET_FILE_LIMIT_TIME = 0x0000CED7,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_CLEAR_FILE_LIMIT_TIME = 0x0000CED8,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_CLEAR_FILE_LIMIT_TIME_FAILED = 0x0000CED9,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_SET_FILE_GUID = 0x0000CEDA,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_SET_FILE_GUID_FAILED = 0x0000CEDB,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_GET_FILE_GUID = 0x0000CEDC,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_SET_FILE_OUTSIDE_GUID = 0x0000CEDD,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_SET_FILE_OUTSIDE_GUID_FAILED = 0x0000CEDE,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_GET_FILE_OUTSIDE_GUID = 0x0000CEDF,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_ONE_IN_MODIFY_FILE_KEY = 0x0000CEE0,
	ERROR_DGEP_DG_ENCRYPT_TYPE_DG_VERSION_FOUR_IN_MODIFY_FILE_KEY = 0x0000CEE1,
	ERROR_DGEP_DG_SET_FILE_HEAD_IN_MODIFY_FILE_KEY_FAILED = 0x0000CEE2,
	ERROR_DGEP_DGP_DECRYPT_FILE_WITH_TARGET_OPERATION_NOT_SUPPORT = 0x0000CEE3,
	ERROR_DGEP_DGP_SET_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEE4,
	ERROR_DGEP_DGP_GET_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEE5,
	ERROR_DGEP_DGP_CLEAR_FILE_LIMIT_TIME_OPERATION_NOT_SUPPORT = 0x0000CEE6,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_GUID_FAILED = 0x0000CEE7,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_OUTSIDE_GUID_FAILED = 0x0000CEE8,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_OWNER_FAILED = 0x0000CEE9,
	ERROR_DGEP_DGP_BUFF_NOT_ENOUGH_FOR_FILE_OWNER_IN_GET_FILE_OWNER = 0x0000CEEA,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_PERMISSION_FAILED = 0x0000CEEB,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_AUTHORIZE_GUID_FAILED = 0x0000CEEC,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_LOG_INFO_FAILED = 0x0000CEED,
	ERROR_DGEP_DGP_BUFF_NOT_ENOUGH_FOR_FILE_OWNER_IN_GET_FILE_LOG_INFO = 0x0000CEEE,
	ERROR_DGEP_DGP_SET_FILE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEEF,
	ERROR_DGEP_DGP_GET_FILE_GUID_OPERATION_NOT_SUPPORT = 0x0000CEF0,
	ERROR_DGEP_DG_CREATE_FILE_IN_SET_FILE_HEAD_FAILED = 0x0000CEF1,
	ERROR_DGEP_DGP_CREATE_FILE_IN_SET_FILE_HEAD_FAILED = 0x0000CEF2,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_SET_FILE_LEVEL_FAILED = 0x0000CEF3,
	ERROR_DGEP_DGP_VERSION_FIVE_LEVEL_CHECK_CODE_NOT_CONSISTENT_IN_GET_FILE_LEVEL = 0x0000CEF4,
	ERROR_DGEP_DGP_SET_FILE_HEAD_IN_MODIFY_FILE_KEY_FAILED = 0x0000CEF5,
	ERROR_DGEP_DG_CREATE_FILE_IN_DECRYPT_FILE_FAILED = 0x0000CEF6,
	ERROR_DGEP_DGP_CREATE_FILE_IN_DECRYPT_FILE_FAILED = 0x0000CEF7,
	ERROR_DGEP_DGP_CREATE_FILE_IN_ENCRYPT_FILE_FAILED = 0x0000CEF8,
	ERROR_DGEP_CW_FILE_ALREADY_ENCRYPTED_IN_ENCRYPT_SIMPLE_FILE = 0x0000CEF9,
	ERROR_DGEP_CW_FILE_ALREADY_ENCRYPTED_IN_ENCRYPT_FILE = 0x0000CEFA,
	
};