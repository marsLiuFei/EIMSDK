//
//  EIMError.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/11/9.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EIMErrorCode) {
    //一般错误
    EIMErrorCodeGeneral = 1,
    //当前登录账号在其它设备登录
    EMErrorCodeLoginOnOtherDevice,
    //用户已经修改了密码
    EMErrorCodeChangePassword,
    //强制用户退出升级
    EMErrorCodeLogoutForceUpdate,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMError : NSObject

/*
*  MARK:错误码
*/
@property (nonatomic) EIMErrorCode code;

/*
*  MARK:错误描述
*/
@property (nonatomic, copy) NSString *errorDescription;

#pragma mark - methond

/*
*  MARK:创建错误实例
*
*  @param aDescription  错误描述
*  @param aCode         错误码
*/
+ (instancetype)errorWithDescription:(NSString *)aDescription code:(EIMErrorCode)aCode;

@end

NS_ASSUME_NONNULL_END
