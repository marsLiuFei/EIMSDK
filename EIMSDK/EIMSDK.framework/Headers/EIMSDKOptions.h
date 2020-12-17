//
//  EIMSDKOptions.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/19.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EIMSDKOptions : NSObject

#pragma mark - 属性

/*
*  MARK:appkey值
*/
@property (nonatomic, copy, readonly) NSString *appkey;

/*
*  MARK:是否自动登录, 默认为YES
*/
@property (nonatomic, assign) BOOL isAutoLogin;

#pragma mark - PrivateDeploy

/*
*  MARK:IM服务器端口
*/
@property (nonatomic, assign) int chatPort;

/*
*  MARK:IM服务器地址
*/
@property (nonatomic, copy) NSString *chatServer;

/*
*  MARK:REST服务器地址
*/
@property (nonatomic, copy) NSString *restServer;

#pragma mark - 方法

/*
*  MARK:SDK设置项实例
*
*  @param aAppKey App的appkey
*/
+ (instancetype)optionsWithAppkey:(NSString *)aAppkey;

@end

NS_ASSUME_NONNULL_END
