//
//  EIMTheme.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/23.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EIMChat.h"

NS_ASSUME_NONNULL_BEGIN

@interface EIMTheme : NSObject

#pragma mark - DB

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
*  MARK:聊天id，单聊为用户id，群聊为群id
*/
@property (nonatomic, copy) NSString *chatId;

#pragma mark - more

@end

NS_ASSUME_NONNULL_END
