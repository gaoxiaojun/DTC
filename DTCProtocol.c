#include "DTCProtocol.h"

#include <assert.h>

void LogonRequest_init(struct s_LogonRequest *msg)
{
    memset(msg, 0, sizeof(struct s_LogonRequest));
    msg->Type = LOGON_REQUEST;
    msg->Size = sizeof(struct s_LogonRequest);
    msg->ProtocolVersion = CURRENT_VERSION;
}

void LogonResponse_init(struct s_LogonResponse *msg)
{
    memset(msg, 0, sizeof(struct s_LogonResponse));
    msg->Type = LOGON_RESPONSE;
    msg->Size = sizeof(struct s_LogonResponse);
    msg->ProtocolVersion = CURRENT_VERSION;
    msg->OrderCancelReplaceSupported = 1;
    msg->MarketDepthIsSupported = 1;
}

void LogoffRequest_init(struct s_LogoffRequest *msg)
{
    memset(msg, 0, sizeof(struct s_LogoffRequest));
    msg->Type = LOGOFF_REQUEST;
    msg->Size = sizeof(struct s_LogoffRequest);
}

void Heartbeat_init(struct s_Heartbeat *msg)
{
    memset(msg, 0, sizeof(struct s_Heartbeat));
    msg->Type = HEARTBEAT;
    msg->Size = sizeof(struct s_Heartbeat);
}

void DisconnectFromServer_init(struct s_DisconnectFromServer *msg)
{
    memset(msg, 0, sizeof(struct s_DisconnectFromServer));
    msg->Type = DISCONNECT_FROM_SERVER_NO_RECONNECT;
    msg->Size = sizeof(struct s_DisconnectFromServer);
}

void MarketDataFeedStatus_init(struct s_MarketDataFeedStatus *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataFeedStatus));
    msg->Type = MARKET_DATA_FEED_STATUS;
    msg->Size = sizeof(struct s_MarketDataFeedStatus);
}

void MarketDataFeedSymbolStatus_init(struct s_MarketDataFeedSymbolStatus *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataFeedSymbolStatus));
    msg->Type = MARKET_DATA_FEED_SYMBOL_STATUS;
    msg->Size = sizeof(struct s_MarketDataFeedSymbolStatus);
}

void MarketDataRequest_init(struct s_MarketDataRequest *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataRequest));
    msg->Type = MARKET_DATA_REQUEST;
    msg->Size = sizeof(struct s_MarketDataRequest);
    msg->RequestActionValue = SUBSCRIBE;
}

void MarketDepthRequest_init(struct s_MarketDepthRequest *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthRequest));
    msg->Type = MARKET_DEPTH_REQUEST;
    msg->Size = sizeof(struct s_MarketDepthRequest);
    msg->RequestActionValue = SUBSCRIBE;
    msg->NumberOfLevels = 10;
}

void MarketDataReject_init(struct s_MarketDataReject *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataReject));
    msg->Type = MARKET_DATA_REJECT;
    msg->Size = sizeof(struct s_MarketDataReject);
}

void MarketDataSnapshot_init(struct s_MarketDataSnapshot *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDataSnapshot));
    msg->Type = MARKET_DATA_SNAPSHOT;
    msg->Size = sizeof(struct s_MarketDataSnapshot);
}

void s_FundamentalDataRequest(s_FundamentalDataRequest *msg)
{
    memset(msg, 0,sizeof(struct s_FundamentalDataRequest));
    msg->Type=FUNDAMENTAL_DATA_REQUEST;
    msg->Size=sizeof(struct s_FundamentalDataRequest);
}

void FundamentalDataResponse_init(struct s_FundamentalDataResponse *msg)
{
    memset(msg, 0, sizeof(struct s_FundamentalDataResponse));
    msg->Type = FUNDAMENTAL_DATA_RESPONSE;
    msg->Size = sizeof(struct s_FundamentalDataResponse);
    msg->DisplayFormat = DISPLAY_FORMAT_UNSET;
}


void MarketDepthFullUpdate20_init(struct s_MarketDepthFullUpdate20 *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthFullUpdate20));
    msg->Type = MARKET_DEPTH_FULL_UPDATE_20;
    msg->Size = sizeof(struct s_MarketDepthFullUpdate20);
}

void MarketDepthFullUpdate10_init(struct s_MarketDepthFullUpdate10 *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthFullUpdate10));
    msg->Type = MARKET_DEPTH_FULL_UPDATE_10;
    msg->Size = sizeof(struct s_MarketDepthFullUpdate10);
}

void MarketDepthSnapshotLevel_init(struct s_MarketDepthSnapshotLevel *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthSnapshotLevel));
    msg->Type = MARKET_DEPTH_SNAPSHOT_LEVEL;
    msg->Size = sizeof(struct s_MarketDepthSnapshotLevel);

}

void MarketDepthIncrementalUpdate_init(struct s_MarketDepthIncrementalUpdate *msg)
{

    memset(msg, 0, sizeof(struct s_MarketDepthIncrementalUpdate));
    msg->Type = MARKET_DEPTH_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_MarketDepthIncrementalUpdate);

}

void MarketDepthIncrementalUpdateCompact_init(struct s_MarketDepthIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthIncrementalUpdateCompact));
    msg->Type = MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_MarketDepthIncrementalUpdateCompact);
}

void SettlementIncrementalUpdate_init(struct s_SettlementIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_SettlementIncrementalUpdate));
    msg->Type = SETTLEMENT_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_SettlementIncrementalUpdate);
}

void DailyOpenIncrementalUpdate_init(struct s_DailyOpenIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyOpenIncrementalUpdate));
    msg->Type = DAILY_OPEN_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyOpenIncrementalUpdate);
}

void MarketDepthReject_init(struct s_MarketDepthReject *msg)
{
    memset(msg, 0, sizeof(struct s_MarketDepthReject));
    msg->Type = MARKET_DEPTH_REJECT;
    msg->Size = sizeof(struct s_MarketDepthReject);
}

void TradeIncrementalUpdate_init(struct s_TradeIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_TradeIncrementalUpdate));
    msg->Type = TRADE_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_TradeIncrementalUpdate);
}

void QuoteIncrementalUpdate_init(struct s_QuoteIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_QuoteIncrementalUpdate));
    msg->Type = QUOTE_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_QuoteIncrementalUpdate);
    msg->BidPrice = DBL_MAX;
    msg->AskPrice = DBL_MAX;
}

void QuoteIncrementalUpdateCompact_init(struct s_QuoteIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_QuoteIncrementalUpdateCompact));
    msg->Type = QUOTE_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_QuoteIncrementalUpdateCompact);
    msg->BidPrice = FLT_MAX;
    msg->AskPrice = FLT_MAX;
}

void TradeIncrementalUpdateCompact_init(struct s_TradeIncrementalUpdateCompact *msg)
{
    memset(msg, 0, sizeof(struct s_TradeIncrementalUpdateCompact));
    msg->Type = TRADE_INCREMENTAL_UPDATE_COMPACT;
    msg->Size = sizeof(struct s_TradeIncrementalUpdateCompact);
}

void DailyVolumeIncrementalUpdate_init(struct s_DailyVolumeIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyVolumeIncrementalUpdate));
    msg->Type = DAILY_VOLUME_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyVolumeIncrementalUpdate);
}

void OpenInterestIncrementalUpdate_init(struct s_OpenInterestIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_OpenInterestIncrementalUpdate));
    msg->Type = OPEN_INTEREST_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_OpenInterestIncrementalUpdate);
}

void DailyHighIncrementalUpdate_init(struct s_DailyHighIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyHighIncrementalUpdate));
    msg->Type = DAILY_HIGH_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyHighIncrementalUpdate);
}

void DailyLowIncrementalUpdate_init(struct s_DailyLowIncrementalUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_DailyLowIncrementalUpdate));
    msg->Type = DAILY_LOW_INCREMENTAL_UPDATE;
    msg->Size = sizeof(struct s_DailyLowIncrementalUpdate);
}

void SubmitNewSingleOrder_init(struct s_SubmitNewSingleOrder *msg)
{
    memset(msg, 0, sizeof(struct s_SubmitNewSingleOrder));
    msg->Type = SUBMIT_NEW_SINGLE_ORDER;
    msg->Size = sizeof(struct s_SubmitNewSingleOrder);
}

void CancelReplaceOrder_init(struct s_CancelReplaceOrder *msg)
{
    memset(msg, 0, sizeof(struct s_CancelReplaceOrder));
    msg->Type = CANCEL_REPLACE_ORDER;
    msg->Size = sizeof(struct s_CancelReplaceOrder);
}

void CancelOrder_init(struct s_CancelOrder *msg)
{
    memset(msg, 0, sizeof(struct s_CancelOrder));
    msg->Type = CANCEL_ORDER;
    msg->Size = sizeof(struct s_CancelOrder);
}

void SubmitNewOCOOrder_init(struct s_SubmitNewOCOOrder *msg)
{
    memset(msg, 0, sizeof(struct s_SubmitNewOCOOrder));
    msg->Type = SUBMIT_NEW_OCO_ORDER;
    msg->Size = sizeof(struct s_SubmitNewOCOOrder);
}

void OpenOrdersRequest_init(struct s_OpenOrdersRequest *msg)
{
    memset(msg, 0, sizeof(struct s_OpenOrdersRequest));
    msg->Type = OPEN_ORDERS_REQUEST;
    msg->Size = sizeof(struct s_OpenOrdersRequest);
    msg->RequestAllOpenOrders = 1;
}

void HistoricalOrderFillsRequest_init(struct s_HistoricalOrderFillsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalOrderFillsRequest));
    msg->Type = HISTORICAL_ORDER_FILLS_REQUEST;
    msg->Size = sizeof(struct s_HistoricalOrderFillsRequest);
}

void CurrentPositionsRequest_init(struct s_CurrentPositionsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_CurrentPositionsRequest));
    msg->Type = CURRENT_POSITIONS_REQUEST;
    msg->Size = sizeof(struct s_CurrentPositionsRequest);
}

void CurrentPositionsRequestReject_init(struct s_CurrentPositionsRequestReject *msg)
{
    memset(msg, 0, sizeof(struct s_CurrentPositionsRequestReject));
    msg->Type = CURRENT_POSITIONS_REQUEST_REJECT;
    msg->Size = sizeof(struct s_CurrentPositionsRequestReject);
}

void OrderUpdateReport_init(struct s_OrderUpdateReport *msg)
{
    memset(msg, 0, sizeof(struct s_OrderUpdateReport));
    msg->Type = ORDER_UPDATE_REPORT;
    msg->Size = sizeof(struct s_OrderUpdateReport);

    /* The following initializations indicate to the Client that these variables are in an unset state and their values should not be used */
    msg->Price1 = DBL_MAX;
    msg->Price2 = DBL_MAX;

    msg->OrderQuantity = DBL_MAX;
    msg->FilledQuantity = DBL_MAX;
    msg->RemainingQuantity = DBL_MAX;
    msg->AverageFillPrice = DBL_MAX;

    msg->LastFillPrice = DBL_MAX;
    msg->LastFillQuantity = DBL_MAX;
}

void OpenOrdersRequestReject_init(struct s_OpenOrdersRequestReject *msg)
{
    memset(msg, 0, sizeof(struct s_OpenOrdersRequestReject));
    msg->Type = OPEN_ORDERS_REQUEST_REJECT;
    msg->Size = sizeof(struct s_OpenOrdersRequestReject);
}

void HistoricalOrderFillReport_init(struct s_HistoricalOrderFillReport *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalOrderFillReport));
    msg->Type = HISTORICAL_ORDER_FILL_REPORT;
    msg->Size = sizeof(struct s_HistoricalOrderFillReport);
}

void PositionReport_init(struct s_PositionReport *msg)
{
    memset(msg, 0, sizeof(struct s_PositionReport));
    msg->Type = POSITION_REPORT;
    msg->Size = sizeof(struct s_PositionReport);
}

void AccountsRequest_init(struct s_AccountsRequest *msg)
{
    memset(msg, 0, sizeof(struct s_AccountsRequest));
    msg->Type = ACCOUNTS_REQUEST;
    msg->Size = sizeof(struct s_AccountsRequest);
}

void AccountListResponse_init(struct s_AccountListResponse *msg)
{
    memset(msg, 0, sizeof(struct s_AccountListResponse));
    msg->Type = ACCOUNT_LIST_RESPONSE;
    msg->Size = sizeof(struct s_AccountListResponse);
}

void ExchangeListRequest_init(struct s_ExchangeListRequest *msg)
{
    memset(msg, 0, sizeof(struct s_ExchangeListRequest));
    msg->Type = EXCHANGE_LIST_REQUEST;
    msg->Size = sizeof(struct s_ExchangeListRequest);
}

void ExchangeListResponse_init(struct s_ExchangeListResponse *msg)
{
    memset(msg, 0, sizeof(struct s_ExchangeListResponse));
    msg->Type = EXCHANGE_LIST_RESPONSE;
    msg->Size = sizeof(struct s_ExchangeListResponse);
}

void SymbolsForExchangeRequest_init(struct s_SymbolsForExchangeRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SymbolsForExchangeRequest));
    msg->Type = SYMBOLS_FOR_EXCHANGE_REQUEST;
    msg->Size = sizeof(struct s_SymbolsForExchangeRequest);
}

void UnderlyingSymbolsForExchangeRequest_init(struct s_UnderlyingSymbolsForExchangeRequest *msg)
{
    memset(msg, 0, sizeof(struct s_UnderlyingSymbolsForExchangeRequest));
    msg->Type = UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
    msg->Size = sizeof(struct s_UnderlyingSymbolsForExchangeRequest);
}

void SymbolsForUnderlyingRequest_init(struct s_SymbolsForUnderlyingRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SymbolsForUnderlyingRequest));
    msg->Type = SYMBOLS_FOR_UNDERLYING_REQUEST;
    msg->Size = sizeof(struct s_SymbolsForUnderlyingRequest);
}

void SymbolSearchByDescriptionRequest(s_SymbolSearchByDescriptionRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SymbolSearchByDescriptionRequest));
    msg->Type=SYMBOL_SEARCH_BY_DESCRIPTION;
    msg->Size=sizeof(struct s_SymbolSearchByDescriptionRequest);
}

void SecurityDefinitionForSymbolRequest_init(struct s_SecurityDefinitionForSymbolRequest *msg)
{
    memset(msg, 0, sizeof(struct s_SecurityDefinitionForSymbolRequest));
    msg->Type = SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
    msg->Size = sizeof(struct s_SecurityDefinitionForSymbolRequest);
}

void SecurityDefinitionResponse_init(struct s_SecurityDefinitionResponse *msg)
{
    memset(msg, 0, sizeof(struct s_SecurityDefinitionResponse));
    msg->Type = SECURITY_DEFINITION_RESPONSE;
    msg->Size = sizeof(struct s_SecurityDefinitionResponse);
}

void AccountBalanceUpdate_init(struct s_AccountBalanceUpdate *msg)
{
    memset(msg, 0, sizeof(struct s_AccountBalanceUpdate));
    msg->Type = ACCOUNT_BALANCE_UPDATE;
    msg->Size = sizeof(struct s_AccountBalanceUpdate);
}

void UserMessage_init(struct s_UserMessage *msg)
{
    memset(msg, 0, sizeof(struct s_UserMessage));
    msg->Type = USER_MESSAGE;
    msg->Size = sizeof(struct s_UserMessage);
    msg->PopupMessage = 1;
}

void GeneralLogMessage_init(struct s_GeneralLogMessage *msg)
{
    memset(msg, 0, sizeof(struct s_GeneralLogMessage));
    msg->Type = GENERAL_LOG_MESSAGE;
    msg->Size = sizeof(struct s_GeneralLogMessage);
}

void HistoricalPriceDataRequest_init(struct s_HistoricalPriceDataRequest *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataRequest));
    msg->Type = HISTORICAL_PRICE_DATA_REQUEST;
    msg->Size = sizeof(struct s_HistoricalPriceDataRequest);
}

void HistoricalPriceDataHeaderResponse_init(struct s_HistoricalPriceDataHeaderResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataHeaderResponse));
    msg->Type = HISTORICAL_PRICE_DATA_HEADER_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataHeaderResponse);
}

void HistoricalPriceDataReject_init(struct s_HistoricalPriceDataReject *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataReject));
    msg->Type = HISTORICAL_PRICE_DATA_REJECT;
    msg->Size = sizeof(struct s_HistoricalPriceDataReject);
}

void HistoricalPriceDataRecordResponse_init(struct s_HistoricalPriceDataRecordResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataRecordResponse));
    msg->Type = HISTORICAL_PRICE_DATA_RECORD_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataRecordResponse);
}

void HistoricalPriceDataTickRecordResponse_init(struct s_HistoricalPriceDataTickRecordResponse *msg)
{
    memset(msg, 0, sizeof(struct s_HistoricalPriceDataTickRecordResponse));
    msg->Type = HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE;
    msg->Size = sizeof(struct s_HistoricalPriceDataTickRecordResponse);
}

int get_request_message_size(uint16_t msg_type)
{
    int msg_size;

    switch (msg_type) {
    case LOGON_REQUEST:
        msg_size = sizeof(s_LogonRequest);
        break;
    case LOGOFF_REQUEST:
        msg_size = sizeof(s_LogoffRequest);
        break;
    case HEARTBEAT:
        msg_size = sizeof(s_Heartbeat);
        break;
    case MARKET_DATA_REQUEST:
        msg_size = sizeof(s_MarketDataRequest);
        break;
    case MARKET_DEPTH_REQUEST:
        msg_size = sizeof(s_MarketDepthRequest);
        break;
    case FUNDAMENTAL_DATA_REQUEST:
        msg_size = sizeof(s_FundamentalDataRequest);
        break;
    case SUBMIT_NEW_SINGLE_ORDER:
        msg_size = sizeof(s_SubmitNewSingleOrder);
        break;
    case SUBMIT_NEW_OCO_ORDER:
        msg_size = sizeof(s_SubmitNewOCOOrder);
        break;
    case CANCEL_REPLACE_ORDER:
        msg_size = sizeof(s_CancelReplaceOrder);
        break;
    case CANCEL_ORDER:
        msg_size = sizeof(s_CancelOrder);
        break;
    case OPEN_ORDERS_REQUEST:
        msg_size = sizeof(s_OpenOrdersRequest);
        break;
    case HISTORICAL_ORDER_FILLS_REQUEST:
        msg_size = sizeof(s_HistoricalOrderFillsRequest);
        break;
    case CURRENT_POSITIONS_REQUEST:
        msg_size = sizeof(s_CurrentPositionsRequest);
        break;
    case ACCOUNTS_REQUEST:
        msg_size = sizeof(s_AccountsRequest);
        break;
    case EXCHANGE_LIST_REQUEST:
        msg_size = sizeof(s_ExchangeListRequest);
        break;
    case SYMBOLS_FOR_EXCHANGE_REQUEST:
        msg_size = sizeof(s_SymbolsForExchangeRequest);
        break;
    case UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST:
        msg_size = sizeof(s_UnderlyingSymbolsForExchangeRequest);
        break;
    case SYMBOLS_FOR_UNDERLYING_REQUEST:
        msg_size = sizeof(s_SymbolsForUnderlyingRequest);
        break;
    case SECURITY_DEFINITION_FOR_SYMBOL_REQUEST:
        msg_size = sizeof(s_SecurityDefinitionForSymbolRequest);
        break;
    case SYMBOL_SEARCH_BY_DESCRIPTION:
        msg_size = sizeof(s_SymbolSearchByDescriptionRequest);
        break;
    case HISTORICAL_PRICE_DATA_REQUEST:
        msg_size = sizeof(s_HistoricalPriceDataRequest);
        break;
    default:
        msg_size = 0;
        assert(msg_size != 0);
        break;
    }
    return msg_size;
}

int get_respone_message_size(uint16_t msg_type)
{
    int msg_size;

    switch(msg_type) {
    // Authentication and connection monitoring
    case LOGON_RESPONSE:
        msg_size = sizeof(s_LogonResponse);
        break;
    case HEARTBEAT:
        msg_size = sizeof(s_Heartbeat);
        break;
    case DISCONNECT_FROM_SERVER_NO_RECONNECT:
        msg_size = sizeof(s_DisconnectFromServer);
        break;
    // Market data
    case MARKET_DATA_FEED_STATUS:
        msg_size = sizeof(s_MarketDataFeedStatus);
        break;
    case MARKET_DATA_REJECT:
        msg_size = sizeof(s_MarketDataReject);
        break;
    case MARKET_DATA_SNAPSHOT:
        msg_size = sizeof(s_MarketDataSnapshot);
        break;
    case MARKET_DEPTH_FULL_UPDATE_20:
        msg_size = sizeof(s_MarketDepthFullUpdate20);
        break;
    case MARKET_DEPTH_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_MarketDepthIncrementalUpdate);
        break;
    case TRADE_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_TradeIncrementalUpdate);
        break;
    case QUOTE_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_QuoteIncrementalUpdate);
        break;
    case FUNDAMENTAL_DATA_RESPONSE:
        msg_size = sizeof(s_FundamentalDataResponse);
        break;
    case TRADE_INCREMENTAL_UPDATE_COMPACT:
        msg_size = sizeof(s_TradeIncrementalUpdateCompact);
        break;
    case DAILY_VOLUME_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_DailyVolumeIncrementalUpdate);
        break;
    case DAILY_HIGH_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_DailyHighIncrementalUpdate);
        break;
    case DAILY_LOW_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_DailyLowIncrementalUpdate);
        break;
    case MARKET_DATA_FEED_SYMBOL_STATUS:
        msg_size = sizeof(s_MarketDataFeedSymbolStatus);
        break;
    case QUOTE_INCREMENTAL_UPDATE_COMPACT:
        msg_size = sizeof(s_QuoteIncrementalUpdateCompact);
        break;
    case MARKET_DEPTH_INCREMENTAL_UPDATE_COMPACT:
        msg_size = sizeof(s_MarketDepthIncrementalUpdateCompact);
        break;
    case SETTLEMENT_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_SettlementIncrementalUpdate);
        break;
    case DAILY_OPEN_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_DailyOpenIncrementalUpdate);
        break;
    case MARKET_DEPTH_REJECT:
        msg_size = sizeof(s_MarketDepthReject);
        break;
    case MARKET_DEPTH_SNAPSHOT_LEVEL:
        msg_size = sizeof(s_MarketDepthSnapshotLevel);
        break;
    case MARKET_DEPTH_FULL_UPDATE_10:
        msg_size = sizeof(s_MarketDepthFullUpdate10);
        break;
    case OPEN_INTEREST_INCREMENTAL_UPDATE:
        msg_size = sizeof(s_OpenInterestIncrementalUpdate);
        break;
    // Trading related
    case ORDER_UPDATE_REPORT:
        msg_size = sizeof(s_OrderUpdateReport);
        break;
    case OPEN_ORDERS_REQUEST_REJECT:
        msg_size = sizeof(s_OpenOrdersRequestReject);
        break;
    case HISTORICAL_ORDER_FILL_REPORT:
        msg_size = sizeof(s_HistoricalOrderFillReport);
        break;
    case POSITION_REPORT:
        msg_size = sizeof(s_PositionReport);
        break;
    case CURRENT_POSITIONS_REQUEST_REJECT:
        msg_size = sizeof(s_CurrentPositionsRequestReject);
        break;
    // Account list
    case ACCOUNT_LIST_RESPONSE:
        msg_size = sizeof(s_AccountListResponse);
        break;
    // Symbol discovery and security definitions
    case EXCHANGE_LIST_RESPONSE:
        msg_size = sizeof(s_ExchangeListResponse);
        break;
    case SECURITY_DEFINITION_RESPONSE:
        msg_size = sizeof(s_SecurityDefinitionResponse);
        break;
    // Account balance
    case ACCOUNT_BALANCE_UPDATE:
        msg_size = sizeof(s_AccountBalanceUpdate);
        break;
    // Logging
    case USER_MESSAGE:
        msg_size = sizeof(s_UserMessage);
        break;
    case GENERAL_LOG_MESSAGE:
        msg_size = sizeof(s_GeneralLogMessage);
        break;
    // Historical price data
    case HISTORICAL_PRICE_DATA_HEADER_RESPONSE:
        msg_size = sizeof(s_HistoricalPriceDataHeaderResponse);
        break;
    case HISTORICAL_PRICE_DATA_REJECT:
        msg_size = sizeof(s_HistoricalPriceDataReject);
        break;
    case HISTORICAL_PRICE_DATA_RECORD_RESPONSE:
        msg_size = sizeof(s_HistoricalPriceDataRecordResponse);
        break;
    case HISTORICAL_PRICE_DATA_TICK_RECORD_RESPONSE:
        msg_size = sizeof(s_HistoricalPriceDataTickRecordResponse);
        break;
    default:
        msg_size = 0;
        assert(msg_size != 0);
        break;
    }

    return msg_size;
}
