#include "TapJson.h"

#if PLATFORM_ANDROID || PLATFORM_IOS

TSharedPtr<FJsonObject> TapJson::Parse(FString json)
{
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(json);
    TSharedPtr<FJsonObject> Result;
    bool parseSuccess = FJsonSerializer::Deserialize(Reader, Result);
    return Result;
}

FString TapJson::ToJSON(TSharedPtr<FJsonObject> jsonObject)
{
    FString OutputString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(jsonObject.ToSharedRef(), Writer);
    return OutputString;
}

FString TapJson::ConstructorCommand(FString serviceName, FString method, FString args, bool callback, FString callbackId,bool onceTime)
{
    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonOutString);
    Writer->WriteObjectStart();
    Writer->WriteValue(TEXT("service"), serviceName);
    Writer->WriteValue(TEXT("method"), method);
    Writer->WriteValue(TEXT("args"), args);
    Writer->WriteValue(TEXT("callback"), callback);
    Writer->WriteValue(TEXT("callbackId"), callbackId);
    Writer->WriteValue(TEXT("onceTime"), onceTime);
    Writer->WriteObjectEnd();
    Writer->Close();
    return JsonOutString;
}

#endif
