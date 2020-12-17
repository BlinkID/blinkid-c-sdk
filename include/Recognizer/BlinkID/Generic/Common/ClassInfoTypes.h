/**
 * @file ClassInfoTypes.h
 *
 * Copyright (c)2020 MicroBlink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef CLASSINFOTYPES_H_INCLUDED
#define CLASSINFOTYPES_H_INCLUDED

#include <Recognizer/Export.h>

/** Document country */
enum MBCountry
{
    MB_COUNTRY_NONE                   = 0,
    MB_COUNTRY_ALBANIA                = 1,
    MB_COUNTRY_ALGERIA                = 2,
    MB_COUNTRY_ARGENTINA              = 3,
    MB_COUNTRY_AUSTRALIA              = 4,
    MB_COUNTRY_AUSTRIA                = 5,
    MB_COUNTRY_AZERBAIJAN             = 6,
    MB_COUNTRY_BAHRAIN                = 7,
    MB_COUNTRY_BANGLADESH             = 8,
    MB_COUNTRY_BELGIUM                = 9,
    MB_COUNTRY_BOSNIA_AND_HERZEGOVINA = 10,
    MB_COUNTRY_BRUNEI                 = 11,
    MB_COUNTRY_BULGARIA               = 12,
    MB_COUNTRY_CAMBODIA               = 13,
    MB_COUNTRY_CANADA                 = 14,
    MB_COUNTRY_CHILE                  = 15,
    MB_COUNTRY_COLOMBIA               = 16,
    MB_COUNTRY_COSTA_RICA             = 17,
    MB_COUNTRY_CROATIA                = 18,
    MB_COUNTRY_CYPRUS                 = 19,
    MB_COUNTRY_CZECHIA                = 20,
    MB_COUNTRY_DENMARK                = 21,
    MB_COUNTRY_DOMINICAN_REPUBLIC     = 22,
    MB_COUNTRY_EGYPT                  = 23,
    MB_COUNTRY_ESTONIA                = 24,
    MB_COUNTRY_FINLAND                = 25,
    MB_COUNTRY_FRANCE                 = 26,
    MB_COUNTRY_GEORGIA                = 27,
    MB_COUNTRY_GERMANY                = 28,
    MB_COUNTRY_GHANA                  = 29,
    MB_COUNTRY_GREECE                 = 30,
    MB_COUNTRY_GUATEMALA              = 31,
    MB_COUNTRY_HONG_KONG              = 32,
    MB_COUNTRY_HUNGARY                = 33,
    MB_COUNTRY_INDIA                  = 34,
    MB_COUNTRY_INDONESIA              = 35,
    MB_COUNTRY_IRELAND                = 36,
    MB_COUNTRY_ISRAEL                 = 37,
    MB_COUNTRY_ITALY                  = 38,
    MB_COUNTRY_JORDAN                 = 39,
    MB_COUNTRY_KAZAKHSTAN             = 40,
    MB_COUNTRY_KENYA                  = 41,
    MB_COUNTRY_KOSOVO                 = 42,
    MB_COUNTRY_KUWAIT                 = 43,
    MB_COUNTRY_LATVIA                 = 44,
    MB_COUNTRY_LITHUANIA              = 45,
    MB_COUNTRY_MALAYSIA               = 46,
    MB_COUNTRY_MALDIVES               = 47,
    MB_COUNTRY_MALTA                  = 48,
    MB_COUNTRY_MAURITIUS              = 49,
    MB_COUNTRY_MEXICO                 = 50,
    MB_COUNTRY_MOROCCO                = 51,
    MB_COUNTRY_NETHERLANDS            = 52,
    MB_COUNTRY_NEW_ZEALAND            = 53,
    MB_COUNTRY_NIGERIA                = 54,
    MB_COUNTRY_PAKISTAN               = 55,
    MB_COUNTRY_PANAMA                 = 56,
    MB_COUNTRY_PARAGUAY               = 57,
    MB_COUNTRY_PHILIPPINES            = 58,
    MB_COUNTRY_POLAND                 = 59,
    MB_COUNTRY_PORTUGAL               = 60,
    MB_COUNTRY_PUERTO_RICO            = 61,
    MB_COUNTRY_QATAR                  = 62,
    MB_COUNTRY_ROMANIA                = 63,
    MB_COUNTRY_RUSSIA                 = 64,
    MB_COUNTRY_SAUDI_ARABIA           = 65,
    MB_COUNTRY_SERBIA                 = 66,
    MB_COUNTRY_SINGAPORE              = 67,
    MB_COUNTRY_SLOVAKIA               = 68,
    MB_COUNTRY_SLOVENIA               = 69,
    MB_COUNTRY_SOUTH_AFRICA           = 70,
    MB_COUNTRY_SPAIN                  = 71,
    MB_COUNTRY_SWEDEN                 = 72,
    MB_COUNTRY_SWITZERLAND            = 73,
    MB_COUNTRY_TAIWAN                 = 74,
    MB_COUNTRY_THAILAND               = 75,
    MB_COUNTRY_TUNISIA                = 76,
    MB_COUNTRY_TURKEY                 = 77,
    MB_COUNTRY_UAE                    = 78,
    MB_COUNTRY_UGANDA                 = 79,
    MB_COUNTRY_UK                     = 80,
    MB_COUNTRY_UKRAINE                = 81,
    MB_COUNTRY_USA                    = 82,
    MB_COUNTRY_VIETNAM                = 83,
    MB_COUNTRY_BRAZIL                 = 84,
    MB_COUNTRY_NORWAY                 = 85,
    MB_COUNTRY_OMAN                   = 86,
    MB_COUNTRY_ECUADOR                = 87,
    MB_COUNTRY_EL_SALVADOR            = 88,
    MB_COUNTRY_SRI_LANKA              = 89,
    MB_COUNTRY_PERU                   = 90,
    MB_COUNTRY_URUGUAY                = 91,
    MB_COUNTRY_BAHAMAS                = 92,
    MB_COUNTRY_BERMUDA                = 93,
    MB_COUNTRY_BOLIVIA                = 94,
    MB_COUNTRY_CHINA                  = 95,
    MB_COUNTRY_EUROPEAN_UNION         = 96,
    MB_COUNTRY_HAITI                  = 97,
    MB_COUNTRY_HONDURAS               = 98,
    MB_COUNTRY_ICELAND                = 99,
    MB_COUNTRY_JAPAN                  = 100,
    MB_COUNTRY_LUXEMBOURG             = 101,
    MB_COUNTRY_MONTENEGRO             = 102,
    MB_COUNTRY_NICARAGUA              = 103,
    MB_COUNTRY_SOUTH_KOREA            = 104,
    MB_COUNTRY_VENEZUELA              = 105,
    MB_COUNTRY_COUNT                  = 106
};

/**
 * @brief Typedef for MBCountry enum.
 */
MB_EXPORTED_TYPE typedef enum MBCountry MBCountry;

/** Document region. */
enum MBRegion
{
    MB_REGION_NONE                         = 0,
    MB_REGION_ALABAMA                      = 1,
    MB_REGION_ALASKA                       = 2,
    MB_REGION_ALBERTA                      = 3,
    MB_REGION_ARIZONA                      = 4,
    MB_REGION_ARKANSAS                     = 5,
    MB_REGION_AUSTRALIAN_CAPITAL_TERRITORY = 6,
    MB_REGION_BRITISH_COLUMBIA             = 7,
    MB_REGION_CALIFORNIA                   = 8,
    MB_REGION_COLORADO                     = 9,
    MB_REGION_CONNECTICUT                  = 10,
    MB_REGION_DELAWARE                     = 11,
    MB_REGION_DISTRICT_OF_COLUMBIA         = 12,
    MB_REGION_FLORIDA                      = 13,
    MB_REGION_GEORGIA                      = 14,
    MB_REGION_HAWAII                       = 15,
    MB_REGION_IDAHO                        = 16,
    MB_REGION_ILLINOIS                     = 17,
    MB_REGION_INDIANA                      = 18,
    MB_REGION_IOWA                         = 19,
    MB_REGION_KANSAS                       = 20,
    MB_REGION_KENTUCKY                     = 21,
    MB_REGION_LOUISIANA                    = 22,
    MB_REGION_MAINE                        = 23,
    MB_REGION_MANITOBA                     = 24,
    MB_REGION_MARYLAND                     = 25,
    MB_REGION_MASSACHUSETTS                = 26,
    MB_REGION_MICHIGAN                     = 27,
    MB_REGION_MINNESOTA                    = 28,
    MB_REGION_MISSISSIPPI                  = 29,
    MB_REGION_MISSOURI                     = 30,
    MB_REGION_MONTANA                      = 31,
    MB_REGION_NEBRASKA                     = 32,
    MB_REGION_NEVADA                       = 33,
    MB_REGION_NEW_BRUNSWICK                = 34,
    MB_REGION_NEW_HAMPSHIRE                = 35,
    MB_REGION_NEW_JERSEY                   = 36,
    MB_REGION_NEW_MEXICO                   = 37,
    MB_REGION_NEW_SOUTH_WALES              = 38,
    MB_REGION_NEW_YORK                     = 39,
    MB_REGION_NORTHERN_TERRITORY           = 40,
    MB_REGION_NORTH_CAROLINA               = 41,
    MB_REGION_NORTH_DAKOTA                 = 42,
    MB_REGION_NOVA_SCOTIA                  = 43,
    MB_REGION_OHIO                         = 44,
    MB_REGION_OKLAHOMA                     = 45,
    MB_REGION_ONTARIO                      = 46,
    MB_REGION_OREGON                       = 47,
    MB_REGION_PENNSYLVANIA                 = 48,
    MB_REGION_QUEBEC                       = 49,
    MB_REGION_QUEENSLAND                   = 50,
    MB_REGION_RHODE_ISLAND                 = 51,
    MB_REGION_SASKATCHEWAN                 = 52,
    MB_REGION_SOUTH_AUSTRALIA              = 53,
    MB_REGION_SOUTH_CAROLINA               = 54,
    MB_REGION_SOUTH_DAKOTA                 = 55,
    MB_REGION_TASMANIA                     = 56,
    MB_REGION_TENNESSEE                    = 57,
    MB_REGION_TEXAS                        = 58,
    MB_REGION_UTAH                         = 59,
    MB_REGION_VERMONT                      = 60,
    MB_REGION_VICTORIA                     = 61,
    MB_REGION_VIRGINIA                     = 62,
    MB_REGION_WASHINGTON                   = 63,
    MB_REGION_WESTERN_AUSTRALIA            = 64,
    MB_REGION_WEST_VIRGINIA                = 65,
    MB_REGION_WISCONSIN                    = 66,
    MB_REGION_WYOMING                      = 67,
    MB_REGION_YUKON                        = 68,
    MB_REGION_CIUDAD_DE_MEXICO             = 69,
    MB_REGION_JALISCO                      = 70,
    MB_REGION_NEWFOUNDLAND_AND_LABRADOR    = 71,
    MB_REGION_NUEVO_LEON                   = 72,
    MB_REGION_BAJA_CALIFORNIA              = 73,
    MB_REGION_CHIHUAHUA                    = 74,
    MB_REGION_GUANAJUATO                   = 75,
    MB_REGION_GUERRERO                     = 76,
    MB_REGION_MEXICO                       = 77,
    MB_REGION_MICHOACAN                    = 78,
    MB_REGION_NEW_YORK_CITY                = 79,
    MB_REGION_TAMAULIPAS                   = 80,
    MB_REGION_VERACRUZ                     = 81,
    MB_REGION_COUNT                        = 82
};

/**
 * @brief Typedef for MBRegion enum.
 */
MB_EXPORTED_TYPE typedef enum MBRegion MBRegion;

/** Document type. */
enum MBDocumentType
{
    MB_DOCUMENT_TYPE_NONE                       = 0,
    MB_DOCUMENT_TYPE_CONSULAR_ID                = 1,
    MB_DOCUMENT_TYPE_DL                         = 2,
    MB_DOCUMENT_TYPE_DL_PUBLIC_SERVICES_CARD    = 3,
    MB_DOCUMENT_TYPE_EMPLOYMENT_PASS            = 4,
    MB_DOCUMENT_TYPE_FIN_CARD                   = 5,
    MB_DOCUMENT_TYPE_ID                         = 6,
    MB_DOCUMENT_TYPE_MULTIPURPOSE_ID            = 7,
    MB_DOCUMENT_TYPE_MyKad                      = 8,
    MB_DOCUMENT_TYPE_MyKid                      = 9,
    MB_DOCUMENT_TYPE_MyPR                       = 10,
    MB_DOCUMENT_TYPE_MyTentera                  = 11,
    MB_DOCUMENT_TYPE_PAN_CARD                   = 12,
    MB_DOCUMENT_TYPE_PROFESSIONAL_ID            = 13,
    MB_DOCUMENT_TYPE_PUBLIC_SERVICES_CARD       = 14,
    MB_DOCUMENT_TYPE_RESIDENCE_PERMIT           = 15,
    MB_DOCUMENT_TYPE_RESIDENT_ID                = 16,
    MB_DOCUMENT_TYPE_TEMPORARY_RESIDENCE_PERMIT = 17,
    MB_DOCUMENT_TYPE_VOTER_ID                   = 18,
    MB_DOCUMENT_TYPE_WORK_PERMIT                = 19,
    MB_DOCUMENT_TYPE_iKAD                       = 20,
    MB_DOCUMENT_TYPE_MILITARY_ID                = 21,
    MB_DOCUMENT_TYPE_MyKAS                      = 22,
    MB_DOCUMENT_TYPE_SOCIAL_SECURITY_CARD       = 23,
    MB_DOCUMENT_TYPE_HEALTH_INSURANCE_CARD      = 24,
    MB_DOCUMENT_TYPE_PASSPORT                   = 25,
    MB_DOCUMENT_TYPE_S_PASS                     = 26,
    MB_DOCUMENT_TYPE_ADDRESS_CARD               = 27,
    MB_DOCUMENT_TYPE_ALIEN_ID                   = 28,
    MB_DOCUMENT_TYPE_ALIEN_PASSPORT             = 29,
    MB_DOCUMENT_TYPE_GREEN_CARD                 = 30,
    MB_DOCUMENT_TYPE_MINORS_ID                  = 31,
    MB_DOCUMENT_TYPE_POSTAL_ID                  = 32,
    MB_DOCUMENT_TYPE_PROFESSIONAL_DL            = 33,
    MB_DOCUMENT_TYPE_TAX_ID                     = 34,
    MB_DOCUMENT_TYPE_WEAPON_PERMIT              = 35,
    MB_DOCUMENT_TYPE_COUNT                      = 36
};

/**
 * @brief Typedef for MBDocumentType enum.
 */
MB_EXPORTED_TYPE typedef enum MBDocumentType MBDocumentType;

#endif
