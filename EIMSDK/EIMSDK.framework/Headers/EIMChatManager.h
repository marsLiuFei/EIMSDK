//
//  EIMChatManager.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/13.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//
/*
available:在线;
away:离开;
do not disturb:忙碌;
unavailable:下线;
*/

#import <Foundation/Foundation.h>
#import "EIMMessage.h"
#import "EIMUser.h"
#import "EIMError.h"
#import "EIMChatManagerDelegate.h"
#import <XMPPFramework/GCDMulticastDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface EIMChatManager : NSObject

#pragma mark - delegate

/*
*  MARK:添加回调代理
*
*  @param aDelegate 回调代理
*/
- (void)addDelegate:(id<EIMChatManagerDelegate>)aDelegate;

/*
*  MARK:移除回调代理
*/
- (void)removeDelegate:(id)aDelegate;

/*
*  MARK:多播代理
*/
@property (nonatomic, strong, readonly) GCDMulticastDelegate <EIMChatManagerDelegate> *multicastDelegate;

#pragma mark - send

/*
*  MARK:发送消息
 
*  @param message 消息
*/
- (void)sendMessage:(EIMMessage *)aMessage;

#pragma mark - chat

/*
*  MARK:获取所有聊天
*/
- (NSArray *)getAllChats;

/*
*  MARK:根据chatId查询本地聊天
*/
- (EIMChat *)getChatWithChatId:(NSString *)chatId;

#pragma mark - theme

/*
*  MARK:获取主题列表
*
*  @param chatId 聊天id
*  @param chatType 聊天type
*  @param aCompletionBlock 回调代理
*/
- (void)getAllThemeFromServerWithChatId:(NSString *)chatId
                               chatType:(EIMChatType)chatType
                             completion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

/*
*  MARK:添加主题
*
*  @param chatId 聊天id
*  @param chatType 聊天type
*  @param themeName 主题名称
*  @param aCompletionBlock 回调代理
*/
- (void)addThemeWithChatId:(NSString *)chatId
                  chatType:(EIMChatType)chatType
                 themeName:(NSString *)themeName
                completion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

/*
*  MARK:编辑主题
*
*  @param themeId 主题id
*  @param themeName 主题名称
*  @param aCompletionBlock 回调代理
*/
- (void)changeThemeWithThemeId:(NSString *)themeId
                     themeName:(NSString *)themeName
                    completion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

#pragma mark - message

/*
*  MARK:根据themeId查询分页消息
 
*  @param themeId 主题id
*  @param chatId 聊天id
*  @param chatType 聊天type
*  @param startMessage 开始查询的消息
*  @param aCompletionBlock 回调代理
*/
- (void)getPageMessagesWithThemeId:(NSString *)themeId
                            chatId:(NSString *)chatId
                          chatType:(EIMChatType)chatType
                      startMessage:(nullable EIMMessage *)startMessage
                        completion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

#pragma mark - userOnlineStatus

/*
*  MARK:查询本地保存用户pc在线状态
*
*  @param userId 用户id
*/
- (EIMUserOnlineStatus)getUserPcOnlineStatusWithUserId:(NSString *)userId;

/*
*  MARK:查询本地保存用户pc在线状态
*
*  @param userId 用户id
*/
- (EIMUserOnlineStatus)getUserAppOnlineStatusWithUserId:(NSString *)userId;

#pragma mark - notDisturb

/*
*  MARK:查询本地保存免打扰用户id
*/
- (NSArray *)getNotDisturbUserIds;

@end

NS_ASSUME_NONNULL_END
