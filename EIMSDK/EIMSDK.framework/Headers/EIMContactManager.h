//
//  EIMContactManager.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/19.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMPPFramework/GCDMulticastDelegate.h>
#import "EIMContactManagerDelegate.h"
#import "EIMError.h"

NS_ASSUME_NONNULL_BEGIN

@interface EIMContactManager : NSObject

#pragma mark - delegate

/*
*  MARK:添加回调代理
*
*  @param aDelegate 回调代理
*/
- (void)addDelegate:(id<EIMContactManagerDelegate>)aDelegate;

/*
*  MARK:移除回调代理
*/
- (void)removeDelegate:(id)aDelegate;

/*
*  MARK:多播代理
*/
@property (nonatomic, strong, readonly) GCDMulticastDelegate <EIMContactManagerDelegate> *multicastDelegate;

#pragma mark - contact

/*
*  MARK:查询本地所有联系人
*/
- (NSArray *)getAllContacts;

/*
*  MARK:从服务器查询所有联系人
*
*  @param aCompletionBlock 回调代理
*/
- (void)getAllContactsFromServerWithCompletion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

/*
*  MARK:添加联系人
*
*  @param aUserId 用户id
*  @param aCompletionBlock 回调代理
*/
- (void)addContact:(NSString *)aUserId
        completion:(void (^)(NSString *aUserId, EIMError *aError))aCompletionBlock;

/*
*  MARK:删除联系人
*
*  @param aUserId 用户id
*  @param aIsDeleteChat    是否删除聊天会话
*  @param aCompletionBlock 回调代理
*/
- (void)deleteContact:(NSString *)aUserId
         isDeleteChat:(BOOL)aIsDeleteChat
           completion:(void (^)(NSString *aUserId, EIMError *aError))aCompletionBlock;

#pragma mark - Blacklist

/*
*  MARK:从本地获取黑名单列表
*/
- (NSArray *)getBlackList;

/*
*  MARK:从服务器获取黑名单列表
*
*  @param aCompletionBlock 回调代理
*/
- (void)getBlackListFromServerWithCompletion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

/*
*  MARK:将用户加入黑名单
*
*  @param aUserId 用户id
*  @param aCompletionBlock 回调代理
*/
- (void)addUserToBlackList:(NSString *)aUserId
                completion:(void (^)(NSString *aUserId, EIMError *aError))aCompletionBlock;

/*
*  MARK:将用户移出黑名单
*
*  @param aUserId 用户id
*  @param aCompletionBlock 回调代理
*/
- (void)removeUserFromBlackList:(NSString *)aUserId
                     completion:(void (^)(NSString *aUserId, EIMError *aError))aCompletionBlock;

#pragma mark - user

/*
*  MARK:获取用户简短信息

*  @param userId 用户id
*  @param aCompletionBlock 回调代理
*/
+ (void)getUserShortInfoWithUserId:(NSString *)userId
                        completion:(void (^)(NSString *aUserId, EIMError *aError))aCompletionBlock;

@end

NS_ASSUME_NONNULL_END
