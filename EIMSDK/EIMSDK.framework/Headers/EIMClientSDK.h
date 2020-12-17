//
//  EIMClientSDK.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/22.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIMSDKOptions.h"
#import "EIMChatManager.h"
#import "EIMGroupManager.h"
#import "EIMContactManager.h"
#import "EIMClientSDKDelegate.h"

@class UIApplication;

#define EIMCurrentUserId [EIMClientSDK sharedSDK].currentUser.userId

NS_ASSUME_NONNULL_BEGIN

@interface EIMClientSDK : NSObject

#pragma mark - 属性

/*
*  MARK:当前登录用户
*/
@property (nonatomic, strong, readonly) EIMUser *currentUser;

/*
*  MARK:SDK属性
*/
@property (nonatomic, strong, readonly) EIMSDKOptions *options;

/*
*  MARK:聊天管理
*/
@property (nonatomic, strong, readonly) EIMChatManager *chatManager;

/*
*  MARK:联系人管理
*/
@property (nonatomic, strong, readonly) EIMContactManager *contactManager;

/*
*  MARK:群管理
*/
@property (nonatomic, strong, readonly) EIMGroupManager *groupManager;

/*
*  MARK:SDK是否自动登录上次登录的账号，如果为YES，则sdk会直接登录上次登录且未做退出操作的账号
*/
@property (nonatomic, readonly) BOOL isAutoLogin;

/*
*  MARK:用户是否已登录
*/
@property (nonatomic, readonly) BOOL isLoggedIn;

/*
*  MARK:是否连上聊天服务器
*/
@property (nonatomic, readonly) BOOL isConnected;

/*
*  MARK:设备Token，推送用
*/
@property (nonatomic, copy, readonly) NSString *deviceToken;


#pragma mark - delegate

/*
*  MARK:添加回调代理
*
*  @param aDelegate 回调代理
*/
- (void)addDelegate:(id<EIMClientSDKDelegate>)aDelegate;

/*
*  MARK:移除回调代理
 
*  @param aDelegate 回调代理
*/
- (void)removeDelegate:(id)aDelegate;

/*
*  MARK:多播代理
*/
@property (nonatomic, strong, readonly) GCDMulticastDelegate <EIMClientSDKDelegate> *multicastDelegate;

#pragma mark - 方法

/*
*  MARK:EIMClientSDK实例
*/
+ (EIMClientSDK*)sharedSDK;

/*
*  MARK:初始化sdk配置
 
*  @param aOptions 配置
*/
- (void)initializeSDKWithOptions:(EIMSDKOptions *)aOptions;

/*
*  MARK:注册远程通知成功
*/
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;

/*
*  MARK:注册远程通知失败
*/
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

#pragma mark - User Registeration

#pragma mark - Login

/*
*  MARK:登录REST服务器
*
*  @param aUser 登录用户
*  @param aCompletionBlock 完成的回调
*/
- (void)loginWithUser:(EIMUser *)aUser
              completion:(void (^)(EIMUser *aUser, EIMError *aError))aCompletionBlock;

#pragma mark - Logout

/*
*  MARK:退出
*
*  @param isConflict 是否冲突导致退出
*  @param aCompletionBlock 完成的回调
*/
- (void)logoutWithIsConflict:(BOOL)isConflict
                  completion:(void (^)(EIMError *aError))aCompletionBlock;

#pragma mark - register

/*
*  MARK:客户端注册
*
*  @param aUser 注册用户
*  @param aCompletionBlock 完成的回调
*/
- (void)registerWithUser:(EIMUser *)aUser
              completion:(void (^)(EIMUser *aUser, EIMError *aError))aCompletionBlock;

@end

NS_ASSUME_NONNULL_END
