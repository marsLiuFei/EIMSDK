
Pod::Spec.new do |spec|

  spec.name         = "EIMSDK"
  spec.version      = "0.0.1"
  spec.summary      = "test EIMSDK 1217"

  spec.description  = <<-DESC
  test EIMSDK 12171505
                   DESC

  spec.homepage     = "https://github.com/marsLiuFei/EIMSDK"
 
  spec.license      = "MIT"
  
  spec.author             = { "GaiShiDaYingXiong" => "mars_liu_dev@163.com" }
  
  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/marsLiuFei/EIMSDK.git", :tag => "#{spec.version}" }

  #spec.resource  = 'EIMSDK/Resources.bundle'
  spec.ios.vendored_frameworks = 'EIMSDK/EIMSDK.framework'
   spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
   
  #  spec.source_files = 'EIMSDK/*'
  spec.dependency 'FMDB'
  spec.dependency 'MJExtension'
  spec.dependency 'AFNetworking'
  spec.dependency 'XMPPFramework'

   spec.requires_arc = true
end
