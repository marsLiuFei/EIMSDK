//
//  EIMChat.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/4.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EIMMessage;

typedef NS_ENUM(NSUInteger, EIMChatType) {
    //单聊类型
    EIMChatTypeChat = 1,
    //群聊类型
    EIMChatTypeGroupChat,
    //聊天室类型
    EIMChatTypeRoomChat,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMChat : NSObject

#pragma mark - DB

/*
*  MARK:聊天id，单聊为用户id，群聊为群id
*/
@property (nonatomic, copy) NSString *chatId;

/*
*  MARK:聊天名称
*/
@property (nonatomic, copy) NSString *chatName;

/*
*  MARK:群聊发送方个人名称
*/
@property (nonatomic, copy) NSString *groupSenderName;

/*
*  MARK:聊天类型
*/
@property (nonatomic, assign) EIMChatType chatType;

/*
*  MARK:消息的id
*/
@property (nonatomic, copy) NSString *messageId;

/*
*  MARK:主题id
*/
@property (nonatomic, copy) NSString *themeId;

/*
*  MARK:主题名
*/
@property (nonatomic, copy, nullable) NSString *themeName;

/*
*  MARK:对话中未读取的消息数量
*/
@property (nonatomic, strong) NSNumber *unreadMessagesCount;

/*
*  MARK:at的所有主题id，豆号隔开
*/
@property (nonatomic, copy) NSString *atAllString;

/*
*  MARK:提示语
*/
@property (nonatomic, copy) NSString *tipMsg;

/*
*  MARK:消息日期
*/
@property (nonatomic, strong) NSDate *date;

#pragma mark - more

/*
*  MARK:头像链接
*/
@property (nonatomic, copy, readonly) NSString *chatAvatarUrlString;

/*
*  MARK:最新一条消息
*/
@property (nonatomic, strong, readonly) EIMMessage *latestMessage;

/*
*  MARK:是否免打扰
*/
@property (nonatomic) BOOL isNotDisturb;

/*
*  MARK:是否置顶
*/
@property (nonatomic) BOOL isTopping;

@end

NS_ASSUME_NONNULL_END
