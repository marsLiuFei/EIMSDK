//
//  EIMUser.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/14.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EIMUserOnlineStatus) {
    //离线状态
    EIMUserOnlineStatusOffLine = -1,
    //未知在线状态
    EIMUserOnlineStatusUnknown = 0,
    //在线状态
    EIMUserOnlineStatusOnline = 1,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMUser : NSObject

#pragma mark - DB

/*
*  MARK:用户的id
*/
@property (nonatomic, copy) NSString *userId;

/*
*  MARK:用户名称
*/
@property (nonatomic, copy) NSString *username;

/*
*  MARK:性别
*/
@property (nonatomic, copy) NSString *gender;

/*
*  MARK:手机号码国家码
*/
@property (nonatomic, copy) NSString *stateCode;

/*
*  MARK:手机号码
*/
@property (nonatomic, copy) NSString *phone;

/*
*  MARK:邮箱
*/
@property (nonatomic, copy) NSString *email;

/*
*  MARK:备注
*/
@property (nonatomic, copy) NSString *mark;

/*
*  MARK:默认备注
*/
@property (nonatomic, copy) NSString *defaultMark;

/*
*  MARK:激活状态
*/
@property (nonatomic, copy) NSString *status;

/*
*  MARK:是否联系人
*/
@property (nonatomic, strong) NSNumber *isContact;

/*
*  MARK:是否手机联系人
*/
@property (nonatomic, strong) NSNumber *isPhoneContact;

/*
*  MARK:用户标签
*/
@property (nonatomic, copy) NSString *userLabel;

/*
*  MARK:联系人手机列表
*/
@property (nonatomic, copy) NSString *contactPhones;

/*
*  MARK:登录密码（未加密）
*/
@property (nonatomic, copy) NSString *password;

#pragma mark - more

/*
*  MARK:短信验证码
*/
@property (nonatomic, copy) NSString *messageCode;

/*
*  MARK:关联用户id
*/
@property (nonatomic, copy) NSString *associateUid;

/*
*  MARK:关联用户密码
*/
@property (nonatomic, copy) NSString *associatePassword;

/*
*  MARK:pc在线状态
*/
@property (nonatomic, assign) EIMUserOnlineStatus pcOnlineStatus;

/*
*  MARK:app在线状态
*/
@property (nonatomic, assign) EIMUserOnlineStatus appOnlineStatus;

/*
*  MARK:头像链接
*/
@property (nonatomic, copy, readonly) NSString *userAvatarUrlString;

/*
*  MARK:生成登录用户
*
*  @param account 手机号码or邮箱
*  @param stateCode 手机号码国家码
*  @param password 登录密码
*/
+ (instancetype)loginUserWithAccount:(NSString *)account
                         stateCode:(NSString *)stateCode
                          password:(NSString *)password;

/*
*  MARK:生成登录用户
*
*  @param account 手机号码or邮箱
*  @param stateCode 手机号码国家码
*  @param messageCode 短信验证码
*/
+ (instancetype)loginUserWithAccount:(NSString *)account
                         stateCode:(NSString *)stateCode
                       messageCode:(NSString *)messageCode;

/*
*  MARK:生成登录用户
*
*  @param account 手机号码or邮箱
*  @param stateCode 手机号码国家码
*  @param messageCode 短信验证码
*/
+ (instancetype)loginUserWithAccount:(NSString *)account
                           stateCode:(NSString *)stateCode
                            password:(NSString *)password
                        associateUid:(NSString *)associateUid
                   associatePassword:(NSString *)associatePassword;

@end

NS_ASSUME_NONNULL_END
