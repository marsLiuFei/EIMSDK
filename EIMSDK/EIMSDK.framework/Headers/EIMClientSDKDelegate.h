//
//  EIMClientSDKDelegate.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/22.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIMError.h"

typedef NS_ENUM(NSUInteger, EIMClientConnectStatus) {
    //默认
    EIMClientConnectStatusDefault = 0,
    //连接中
    EIMClientConnectStatusConnecting,
    //连接成功
    EIMClientConnectStatusConnectSuccess,
    //断开连接
    EIMClientConnectStatusDisconnect,
    //未知的域名
    EIMClientConnectStatusUnknowDomain,
    //服务器拒绝
    EIMClientConnectStatusServerRefused,
    //网络状态差
    EIMClientConnectStatusNetError,
};

NS_ASSUME_NONNULL_BEGIN

@protocol EIMClientSDKDelegate <NSObject>

@optional

/*
*  MARK:SDK连接服务器的状态变化时会接收到该回调
*
*  @param aDelegate 回调代理
*/
- (void)connectStatusDidChange:(EIMClientConnectStatus)aConnectState;

/*
*  MARK:当前登录账号退出时会接收到此回调
*/
- (void)accountDidLogoutWithError:(EIMError *)aError;

/*
*  MARK:SDK连接服务器的状态变化时会接收到该回调
*
*  @param isForceUpdate 是否强制更新
*  @param detail 更新信息
*/
- (void)versionUpdateMessage:(BOOL)isForceUpdate detail:(NSString *)detail;

@end

NS_ASSUME_NONNULL_END
