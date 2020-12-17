//
//  EIMMessageBody.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/30.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EIMMessageBodyType) {
    //文本类型
    EIMMessageBodyTypeText = 1,
    //图片类型
    EIMMessageBodyTypeImage,
    //视频类型
    EIMMessageBodyTypeVideo,
    //位置类型
    EIMMessageBodyTypeLocation,
    //语音类型
    EIMMessageBodyTypeVoice,
    //文件类型
    EIMMessageBodyTypeFile,
    //超级扩展类型
    EIMMessageBodyTypeExtendTypeExtra,
    //扩展类型
    EIMMessageBodyTypeExtendType,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMMessageBody : NSObject

#pragma mark - DB

/*
*  MARK:消息body
*/
@property (nonatomic, copy) NSString *body;

/*
*  MARK:链接
*/
@property (nonatomic, copy) NSString *link;

/*
*  MARK:文件名称
*/
@property (nonatomic, copy) NSString *fileName;

/*
*  MARK:文件大小
*/
@property (nonatomic, copy) NSString *fileSize;

@end

NS_ASSUME_NONNULL_END
