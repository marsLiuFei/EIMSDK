//
//  EIMMessage.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/13.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIMMessageBody.h"
#import "EIMChat.h"

typedef NS_ENUM(NSUInteger, EIMMessageSendStatus) {
    //发送未开始
    EIMMessageSendStatusPending = 1,
    //正在发送
    EIMMessageSendStatusSending,
    //发送成功
    EIMMessageSendStatusSucceed,
    //发送失败
    EIMMessageSendStatusFailed,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMMessage : NSObject

#pragma mark - DB

/*
*  MARK:消息的id
*/
@property (nonatomic, copy) NSString *messageId;

/*
*  MARK:序列号
*/
@property (nonatomic, strong) NSNumber *sequenceId;

/*
*  MARK:所属聊天的id，单聊为用户id，群聊为群id
*/
@property (nonatomic, copy) NSString *chatId;

/*
*  MARK:聊天名称
*/
@property (nonatomic, copy) NSString *chatName;

/*
*  MARK:发送方个人id
*/
@property (nonatomic, copy) NSString *fromId;

/*
*  MARK:群聊发送方个人名称
*/
@property (nonatomic, copy) NSString *groupSenderName;

/*
*  MARK:接收方个人id
*/
@property (nonatomic, copy) NSString *toId;

/*
*  MARK:主题id
*/
@property (nonatomic, copy) NSString *themeId;

/*
*  MARK:主题名
*/
@property (nonatomic, copy, nullable) NSString *themeName;

/*
*  MARK:扩展类型
*/
@property (nonatomic, copy) NSString *extendType;

/*
*  MARK:消息发送状态
*/
@property (nonatomic, assign) EIMMessageSendStatus sendStatus;

/*
*  MARK:消息体类型
*/
@property (nonatomic, assign) EIMMessageBodyType bodyType;

/*
*  MARK:消息体
*/
@property (nonatomic, strong) EIMMessageBody *messageBody;

/*
*  MARK:聊天类型
*/
@property (nonatomic, assign) EIMChatType chatType;

/*
*  MARK:是否企业号
*/
@property (nonatomic, strong) NSNumber *isEnterprise;

/*
*  MARK:是否游客
*/
@property (nonatomic, strong) NSNumber *isGuest;

/*
*  MARK:消息日期
*/
@property (nonatomic, strong) NSDate *date;

/*
*  MARK:提示语
*/
@property (nonatomic, copy) NSString *tipMsg;

#pragma mark - more

/*
*  MARK:头像链接
*/
@property (nonatomic, copy, readonly) NSString *fromAvatarUrlString;

/*
*  MARK:是否已读
*/
@property (nonatomic) BOOL isRead;

@end

NS_ASSUME_NONNULL_END
