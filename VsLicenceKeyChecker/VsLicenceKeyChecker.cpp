/* VocalShifter Licence Key Checker */
/* 本プログラムは、ライセンスキー認証アルゴリズムの実験用プログラムです。 */
/* CreateMD5Text関数は、本ファイルには実装されていません。 */
/* 実際にはLICENSEKEY_NUMは 65536です。以下コードは、サンプルとして、1キーのみテーブルに登録しています。 */

/* This program is an experimental program for license key authentication algorithm. */
/* The CreateMD5Text function is not implemented in this file. */
/* In practice, LICENSEKEY_NUM is 65536. The following code registers only one key to the table as a sample. */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define LICENSE_KEY_NUM (1)
const char *md5hashTable[LICENSE_KEY_NUM]=
{
	"f4b590561720d87652394cd413db26d9",
};

bool CheckVsLicenseKey( int code1, int code2, int code3, int code4 )
{
	char keyStr[41];
	sprintf_s( keyStr, sizeof(keyStr), "%04X%04X%04X%04X-VocalShifter3LicenseKey", code1, code2, code3, code4 );

	char md5hash[33];
	CreateMD5Text( keyStr, md5hash );

	bool hitFlag = false;
	for( int i = 0; i < LICENSE_KEY_NUM; i++ )
	{
		if( strcmp( md5hash, md5hashTable[i] ) == 0 )
		{
			hitFlag = true;
			break;
		}
	}

	return( hitFlag );
}

int main(void)
{
	bool result = CheckVsLicenseKey( 0x0123, 0x4567, 0x89AB, 0xCDEF );
}
