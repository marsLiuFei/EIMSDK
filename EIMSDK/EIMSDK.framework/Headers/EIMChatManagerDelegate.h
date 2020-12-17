//
//  EIMChatManagerDelegate.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/2.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIMTheme.h"

NS_ASSUME_NONNULL_BEGIN

@protocol EIMChatManagerDelegate <NSObject>

@optional

/*
*  MARK:聊天列表发生变化
   
*  @param aChatList  聊天列表<EIMChat>
*/
- (void)chatListDidUpdate:(nullable NSArray *)aChatList;

/*
*  MARK:收到消息
*
*  @param aMessages  消息列表<EIMMessage>
*/
- (void)messagesDidReceive:(NSArray *)aMessages;

/*
*  MARK:收到消息送达服务器回执
*
*  @param aMessages  消息列表<EIMMessage>
*/
- (void)messagesDidDeliverServer:(NSArray *)aMessages;

/*
*  MARK:消息状态发生变化
*
*  @param aMessages  消息<EIMMessage>
*/
- (void)messageStatusDidChange:(EIMMessage *)aMessage;

/*
*  MARK:用户在线状态发生变化
   
*  @param aUserIdArray  发生变化的userIds
*/
- (void)userOnlineStatusDidUpdate:(nullable NSArray *)aUserIdArray;

/*
*  MARK:消息主题发生变化
*
*  @param aMessages  消息<EIMMessage>
*/
- (void)messageThemeDidChange:(EIMTheme *)aTheme;

/*
*  MARK:退出当前主题（在聊天界面是需实现改方法）
*/
- (void)quitCurrentTheme;

@end

NS_ASSUME_NONNULL_END
