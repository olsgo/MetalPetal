//
//  MTIFunctionArgumentsEncoder.h
//  MetalPetal
//
//  Created by YuAo on 2020/7/11.
//

#import <Metal/Metal.h>

// Suppress deprecation warnings for MTLArgument (deprecated in macOS 13.0/iOS 16.0)
// MTLArgument is still functional and needed for backwards compatibility with older Metal APIs
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

NS_ASSUME_NONNULL_BEGIN

@protocol MTIFunctionArgumentEncodingProxy <NSObject>

- (void)encodeBytes:(const void *)bytes length:(NSUInteger)length;

@end

@protocol MTIFunctionArgumentEncoding <NSObject>

+ (BOOL)encodeValue:(id)value argument:(MTLArgument *)argument proxy:(id<MTIFunctionArgumentEncodingProxy>)proxy error:(NSError **)error;

@end

__attribute__((objc_subclassing_restricted))
@interface MTIFunctionArgumentsEncoder : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

+ (BOOL)encodeArguments:(NSArray<MTLArgument *>*)arguments
                 values:(NSDictionary<NSString *, id> *)parameters
           functionType:(MTLFunctionType)functionType
                encoder:(id<MTLCommandEncoder>)encoder
                  error:(NSError **)error;

@end

#pragma clang diagnostic pop

NS_ASSUME_NONNULL_END
