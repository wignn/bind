#include <node.h>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world", v8::NewStringType::kNormal)
                                .ToLocalChecked());
}

void sum(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  double a = 4.4563;


  for (int i = 2; i < 1000000; i++)
  {
    bool isPrime = true;
    for (int j = 2; j * j <= i; ++j)
    {
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
    {
      a += i;
    }
  }

  args.GetReturnValue().Set(a);
}

void isPrismNumber(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  int n = args[0]->Int32Value(isolate->GetCurrentContext()).ToChecked();
  int sum = 0;

  for (int i = 1; i <= n; i++)
  {
    sum += i;
    if (sum == n)
    {
      args.GetReturnValue().Set(true);
      return;
    }
  }

  args.GetReturnValue().Set(false);
}

void Initialize(Local<v8::Object> exports)
{
  NODE_SET_METHOD(exports, "hello", Method);
  NODE_SET_METHOD(exports, "sum", sum);
  NODE_SET_METHOD(exports, "isPrismNumber", isPrismNumber);
}

NODE_MODULE(addon, Initialize)
