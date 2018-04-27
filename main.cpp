#include "stdio.h"
#include "mysql.h"
#include "iostream"
#include "base64.h"

using namespace std;

extern "C" char * base64_encode(UDF_INIT *initid, UDF_ARGS *args,
          char *result, unsigned long *length,
          char *is_null, char *error) {

	Base64 *base = new Base64();
	string str = base->Encode((const unsigned char *)args->args[0], args->lengths[0]);
	memcpy(result, str.c_str(), str.size());
	*length = str.size();
	return result;
}

extern "C" char * base64_decode(UDF_INIT *initid, UDF_ARGS *args,
          char *result, unsigned long *length,
          char *is_null, char *error) {

	Base64 *base = new Base64();
	string str = base->Decode((const char *)args->args[0], args->lengths[0]);
	memcpy(result, str.c_str(), str.size());
	*length = str.size();
	return result;
}

extern "C" my_bool init(UDF_INIT *initid, UDF_ARGS *args, char *message) {
	if (args->arg_count != 1) {
		strcpy(message, "need one argments");
		return 1;
	}
	args->arg_type[0] = STRING_RESULT;
	return 0;
}

extern "C" void deinit(UDF_INIT *initid) {}
extern "C" void reset(UDF_INIT *initid, UDF_ARGS *args,char *is_null, char *error){}
extern "C" void clear(UDF_INIT *initid, char *is_null, char *error){}
extern "C" void add(UDF_INIT *initid, UDF_ARGS *args,char *is_null, char *error){}