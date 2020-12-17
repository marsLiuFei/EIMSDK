//
//  EIMGroupManager.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/19.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMPPFramework/GCDMulticastDelegate.h>
#import "EIMGroupManagerDelegate.h"
#import "EIMError.h"
#import "EIMGroup.h"

NS_ASSUME_NONNULL_BEGIN

@interface EIMGroupManager : NSObject

#pragma mark - delegate

/*
*  MARK:添加回调代理
*
*  @param aDelegate 回调代理
*/
- (void)addDelegate:(id<EIMGroupManagerDelegate>)aDelegate;

/*
*  MARK:移除回调代理
*/
- (void)removeDelegate:(id)aDelegate;

/*
*  MARK:多播代理
*/
@property (nonatomic, strong, readonly) GCDMulticastDelegate <EIMGroupManagerDelegate> *multicastDelegate;

#pragma mark - group

/*
*  MARK:从本地获取用户所有群组
*/
- (NSArray *)getJoinedGroups;

/*
*  MARK:按数目从服务器获取自己加入的群组
*
*  @param aPageNum 第几页
*  @param aPageSize 每页显示的条数
*  @param aCompletionBlock 回调代理
*/
- (void)getJoinedGroupsFromServerWithPage:(NSInteger)aPageNum
                                 pageSize:(NSInteger)aPageSize
                               completion:(void (^)(NSArray *aList, EIMError *aError))aCompletionBlock;

/*
*  MARK:获取群简短信息
 
*  @param groupId 群id
*  @param resultBlock 回调代理
*/
+ (void)getGroupShortInfoWithGroupId:(NSString *)groupId
                          completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:创建普通群
 
*  @param memberUserIds 群成员userId
*  @param aCompletionBlock 回调代理
*/
- (void)createNormalGroupWithMemberUserIds:(NSArray *)memberUserIds
                                completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:创建组织内部群
 
*  @param memberUserIds 群成员userId
*  @param dirId 组织id
*  @param groupName 群名称
*  @param groupAvatar 群头像
*  @param resultBlock 回调代理
*/
- (void)createOrgAttachGroupWithMemberUserIds:(NSArray *)memberUserIds
                                        dirId:(NSString *)dirId
                                    groupName:(NSString *)groupName
                                  groupAvatar:(NSString *)groupAvatar
                                   completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:添加人进群
 
*  @param groupId 群id
*  @param memberUserIds 群成员userId
*  @param groupStyle 群类型
*  @param aCompletionBlock 回调代理
*/
- (void)inviteMemberWithGroupId:(NSString *)groupId
                  memberUserIds:(NSArray *)memberUserIds
                     groupStyle:(EIMGroupStyle)groupStyle
                     completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:退出群组
 
*  @param groupId 群id
*  @param groupStyle 群类型
*  @param aCompletionBlock 回调代理
*/
- (void)leaveGroupWithGroupId:(NSString *)groupId
                   groupStyle:(EIMGroupStyle)groupStyle
                   completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:解散群组
 
*  @param groupId 群id
*  @param groupStyle 群类型
*  @param aCompletionBlock 回调代理
*/
- (void)destroyGroupWithGroupId:(NSString *)groupId
                     groupStyle:(EIMGroupStyle)groupStyle
                     completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:修改群信息
 
*  @param groupId 群id
*  @param groupCatId 群分类id
*  @param groupName 群名称
*  @param groupAvatar 群头像
*  @param groupBrief 群简介
*  @param resultBlock 回调代理
*/
- (void)updateGroupWithGroupId:(NSString *)groupId
                    groupCatId:(NSString *)groupCatId
                     groupName:(NSString *)groupName
                   groupAvatar:(NSString *)groupAvatar
                    groupBrief:(NSString *)groupBrief
                    completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:转让群主（管理员)
 
*  @param groupId 群id
*  @param newOwner 新群主userId
*  @param aCompletionBlock 回调代理
*/
- (void)transferGroupOwnerWithGroupId:(NSString *)groupId
                             newOwner:(NSString *)newOwner
                           completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

/*
*  MARK:移除群组成员
 
*  @param groupId 群id
*  @param memberUserIds 群成员userId
*  @param aCompletionBlock 回调代理
*/
- (void)removeMembersWithGroupId:(NSString *)groupId
                   memberUserIds:(NSString *)memberUserIds
                      completion:(void (^)(EIMGroup *aGroup, EIMError *aError))aCompletionBlock;

@end

NS_ASSUME_NONNULL_END
