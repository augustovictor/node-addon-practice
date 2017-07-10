#include <nan.h>
#include <iostream>
#include <string>

// https://nodeaddons.com/building-an-asynchronous-c-addon-for-node-js-using-nan/

NAN_METHOD(LogMessage) {
    Nan:: HandleScope scope;
    if(info.Length() < 1) {
        Nan::ThrowError("Invalid number of arguments\n");
        return;
    }
    
    cout << info[0]
    auto message = Nan::New<v8::String>("This is a message from c++ code.").ToLocalChecked();
    info.GetReturnValue().Set(message);
}

NAN_MODULE_INIT(Init) {
    NAN_EXPORT(target, LogMessage);
}

NODE_MODULE(moduleLog, Init);