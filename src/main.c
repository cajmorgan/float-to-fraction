#include <node_api.h>
#include "algortihmFrac.h"

napi_value startAlgo(napi_env env, napi_callback_info info);

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 0, startAlgo, NULL, &fn);

  status = napi_set_named_property(env, exports, "start_algo", fn);

  return exports; 

}

napi_value startAlgo(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  double_t number = 0;
  napi_value argv[1], returnString;
  char *string[10];


  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

  status = napi_get_value_double(env, argv[0], &number);

  string[0] = mainAlgo(number);
  
  status = napi_create_string_utf8(env, string[0], NAPI_AUTO_LENGTH, &returnString);

  return returnString;
}



NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)