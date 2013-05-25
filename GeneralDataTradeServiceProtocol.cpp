#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 

#include <stddef.h>
#include "GeneralDataTradeServiceProtocol.h"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

/*==========================================================================*/
int GSP::s_LogonRequest::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetProtocolVersion(int NewValue)
{
	ProtocolVersion = NewValue;
}

/*==========================================================================*/
//Will get the size of the message received over the network
unsigned short GSP::s_LogonRequest::GetMessageSize()
{
	return Size;
}
/*==========================================================================*/
//Performs a safe copy of data into this structure instance from the given data pointer
void GSP::s_LogonRequest::CopyFrom(void * p_SourceData)
{
	memcpy( this, p_SourceData, min(sizeof(GSP::s_LogonResponse), Size) );
}

/*==========================================================================*/
const char * GSP::s_LogonRequest::GetUsername()
{
	// Example to check if member actually exists. This is not needed in this case because this member exists in the first version of this structure.
	if (offsetof(s_LogonRequest,Username ) > Size)
		return "";

	Username[sizeof(Username) - 1 ] = '\0';//Ensure that the null terminator exists

	return Username;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetUsername(const char * NewValue)
{
	strncpy(Username, NewValue, sizeof(Username) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetPassword()
{
	Password[sizeof(Password) - 1 ] = '\0';
	return Password;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetPassword(const char * NewValue)
{
	strncpy(Password, NewValue, sizeof(Password) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetGeneralTextData()
{
	GeneralTextData[sizeof(GeneralTextData) - 1 ] = '\0';
	return GeneralTextData;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetGeneralTextData(const char * NewValue)
{
	strncpy(GeneralTextData, NewValue, sizeof(GeneralTextData) - 1);
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInteger_1()
{
	return Integer_1;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_1(int NewValue)
{
	Integer_1 = NewValue;
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInteger_2()
{
	return Integer_2;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetInteger_2(int NewValue)
{
	Integer_2 = NewValue;
}

/*==========================================================================*/
int GSP::s_LogonRequest::GetInHeartbeatIntervalInSeconds()
{
	return HeartbeatIntervalInSeconds;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHeartbeatIntervalInSeconds(int NewValue)
{
	HeartbeatIntervalInSeconds = NewValue;
}

/*==========================================================================*/
GSP::TradeModeEnum GSP::s_LogonRequest::GetTradeMode()
{
	return TradeMode;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeMode(GSP::TradeModeEnum NewValue)
{
	TradeMode = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetTradeAccount()
{
	TradeAccount[sizeof(TradeAccount) - 1 ] = '\0';
	return TradeAccount;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetTradeAccount(const char * NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonRequest::GetHardwareIdentifier()
{
	HardwareIdentifier[sizeof(HardwareIdentifier) - 1 ] = '\0';
	return HardwareIdentifier;
}

/*==========================================================================*/
void GSP::s_LogonRequest::SetHardwareIdentifier(const char * NewValue)
{
	strncpy(HardwareIdentifier, NewValue, sizeof(HardwareIdentifier) - 1);
}


/*==========================================================================*/
int GSP::s_LogonResponse::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetProtocolVersion(int NewValue)
{
	ProtocolVersion = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_LogonResponse::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
GSP::LogonStatusEnum GSP::s_LogonResponse::GetResult()
{
	return Result;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetResult(LogonStatusEnum NewValue)
{
	Result = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetErrorText()
{
	ErrorText[sizeof(ErrorText) - 1 ] = '\0';
	return ErrorText;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetErrorText(const char * NewValue)
{
	strncpy(ErrorText, NewValue, sizeof(ErrorText) - 1);
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetLogonText()
{
	LogonText[sizeof(LogonText) - 1 ] = '\0';
	return LogonText;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetLogonText(const char * NewValue)
{
	strncpy(LogonText, NewValue, sizeof(LogonText) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetMarketDepthUpdatesBestBidAndAsk()
{
	return MarketDepthUpdatesBestBidAndAsk;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetMarketDepthUpdatesBestBidAndAsk(unsigned char NewValue)
{
	MarketDepthUpdatesBestBidAndAsk = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetTradingIsSupported()
{
	return TradingIsSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetTradingIsSupported(unsigned char NewValue)
{
	TradingIsSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetOCOOrdersSupported()
{
	return OCOOrdersSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetOCOOrdersSupported(unsigned char NewValue)
{
	OCOOrdersSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetOrderCancelReplaceSupported()
{
	return OrderCancelReplaceSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetOrderCancelReplaceSupported(unsigned char NewValue)
{
	OrderCancelReplaceSupported = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetSymbolExchangeDelimiter()
{
	SymbolExchangeDelimiter[sizeof(SymbolExchangeDelimiter) - 1 ] = '\0';
	return SymbolExchangeDelimiter;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetSymbolExchangeDelimiter(const char * NewValue)
{
	strncpy(SymbolExchangeDelimiter, NewValue, sizeof(SymbolExchangeDelimiter) - 1);
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetSecurityDefinitionsSupported()
{
	return SecurityDefinitionsSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetSecurityDefinitionsSupported(unsigned char NewValue)
{
	SecurityDefinitionsSupported = NewValue;
}

/*==========================================================================*/
unsigned char GSP::s_LogonResponse::GetHistoricalPriceDataSupported()
{
	return HistoricalPriceDataSupported;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetHistoricalPriceDataSupported(unsigned char NewValue)
{
	HistoricalPriceDataSupported  = NewValue;
}

/*==========================================================================*/
char * GSP::s_LogonResponse::GetReconnectAddress()
{
	ReconnectAddress[sizeof(ReconnectAddress) - 1 ] = '\0';
	return ReconnectAddress;
}

/*==========================================================================*/
void GSP::s_LogonResponse::SetReconnectAddress(const char * NewValue)
{
	strncpy(ReconnectAddress, NewValue, sizeof(ReconnectAddress) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_Heartbeat::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
unsigned short GSP::s_DisconnectFromServer::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
char * GSP::s_DisconnectFromServer::GetDisconnectReason()
{
	if (offsetof(s_DisconnectFromServer,DisconnectReason ) > Size)
		return "";

	DisconnectReason[sizeof(DisconnectReason) - 1 ] = '\0';
	return DisconnectReason;
}

/*==========================================================================*/
void GSP::s_DisconnectFromServer::SetDisconnectReason(const char * NewValue)
{
	strncpy(DisconnectReason, NewValue, sizeof(DisconnectReason) - 1);
}

/*==========================================================================*/
int GSP::s_ServerReadyToReceive::GetProtocolVersion()
{
	return ProtocolVersion;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetProtocolVersion(int NewValue)
{
	ProtocolVersion = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_ServerReadyToReceive::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServerName()
{
	ServerName[sizeof(ServerName) - 1 ] = '\0';
	return ServerName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerName(const char * NewValue)
{
	strncpy(ServerName, NewValue, sizeof(ServerName) - 1);
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServerVersion()
{
	ServerVersion[sizeof(ServerVersion) - 1 ] = '\0';
	return ServerVersion;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServerVersion(const char * NewValue)
{
	strncpy(ServerVersion, NewValue, sizeof(ServerVersion) - 1);
}

/*==========================================================================*/
char * GSP::s_ServerReadyToReceive::GetServiceProviderName()
{
	ServiceProviderName[sizeof(ServiceProviderName) - 1 ] = '\0';
	return ServiceProviderName;
}

/*==========================================================================*/
void GSP::s_ServerReadyToReceive::SetServiceProviderName(const char * NewValue)
{
	strncpy(ServiceProviderName, NewValue, sizeof(ServiceProviderName) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_ConfigurationRequestFromClient::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataFeedStatus::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
GSP::MarketDataFeedStatusEnum GSP::s_MarketDataFeedStatus::GetStatus()
{
	return Status;
}

/*==========================================================================*/
void GSP::s_MarketDataFeedStatus::SetStatus(GSP::MarketDataFeedStatusEnum NewValue)
{
	Status = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDataRequest::GetRequestActionValue()
{
	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataRequest::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDataRequest::GetSymbol()
{
	Symbol[sizeof(Symbol) - 1 ] = '\0';
	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char * GSP::s_MarketDataRequest::GetExchange()
{
	Exchange[sizeof(Exchange) - 1 ] = '\0';
	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDataRequest::SetExchange(const char * NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthRequest::GetMessageSize()
{
	return Size;
}

/*==========================================================================*/
GSP::RequestActionEnum GSP::s_MarketDepthRequest::GetRequestActionValue()
{
	return RequestActionValue;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetRequestActionValue(GSP::RequestActionEnum NewValue)
{
	RequestActionValue = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDepthRequest::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDepthRequest::GetSymbol()
{
	Symbol[sizeof(Symbol) - 1 ] = '\0';
	return Symbol;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetSymbol(const char * NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
char * GSP::s_MarketDepthRequest::GetExchange()
{
	Exchange[sizeof(Exchange) - 1 ] = '\0';
	return Exchange;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetExchange(const char * NewValue)
{
	strncpy(Exchange, NewValue, sizeof(Exchange) - 1);
}

/*==========================================================================*/
int GSP::s_MarketDepthRequest::GetNumberOfLevels()
{
	return NumberOfLevels;
}

/*==========================================================================*/
void GSP::s_MarketDepthRequest::SetNumberOfLevels(int NewValue)
{
	NumberOfLevels = NewValue;
}

/*==========================================================================*/
unsigned short GSP::s_MarketDataReject::GetMarketDataSymbolID()
{
	return MarketDataSymbolID;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetMarketDataSymbolID(unsigned short NewValue)
{
	MarketDataSymbolID = NewValue;
}

/*==========================================================================*/
char * GSP::s_MarketDataReject::GetRejectText()
{
	RejectText[sizeof(RejectText) - 1 ] = '\0';
	return RejectText;
}

/*==========================================================================*/
void GSP::s_MarketDataReject::SetRejectText(const char * NewValue)
{
	strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
}

/*==========================================================================*/