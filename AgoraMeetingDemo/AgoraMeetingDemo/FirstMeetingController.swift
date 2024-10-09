//
//  FirstMeetingController.swift
//  AgoraMeetingDemo
//
//  Created by jinggang on 2024/9/25.
//

import AgoraFoundation
import Foundation
import FcrUIScene
import FcrCore

var sceneCreator: FcrUISceneCreator?

class FirstMeetingController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        let config = FcrUISceneCreatorConfig(appId: "aed7f253d1c64269b3468c82e918babe",
                                             userId: "123")
        
        config.parameters = privateParameters()
        
        let creator = FcrUISceneCreator(config: config)
        
        let sceneConfig = FcrUISceneConfig(roomId: "999",
                                           roomToken: "007eJxTYLhVKsLZFf3TyeHlEguD3lmHX2881f/aIydcM2s3wy35Ny0KDImpKeZpRqbGKYbJZiZGZpZJxiZmFskWRqmWhhZJiUmpU7XZ0hsCGRlW3OZnZWZgYmAEQhCfmcHQyJgVzlVgMDIwSk6yNDNKTDa1NDA3BTJNkgzMDU2NUoyMTZLMDdgZGICaLC0twToZGQCBLyjL",
                                           userName: "jing",
                                           userRole: FcrUserRole.host,
                                           inviteLink: "",
                                           userProperties: nil,
                                           resource: nil)
        
        creator.launch(config: sceneConfig,
                       cancel: {
            print("cancel")
        }, success: { scene in
            print("success")
        }, failure: { error in
            print("failure")
        }, parent: self)
        sceneCreator = creator
    }
    
    func privateParameters() -> [String: Any] {
        let environment = AgoraDomainNamePoolEnvironment.pro
        
        var coreParameters: [String: Any] = ["console": 1]
        var rteParameters: [String: Any] = ["console": 1]
        
        switch environment {
        case .pri:
            let coreIpList = ["https://api-solutions-private.agoralab.co"]
            let rteIpList = ["https://api-solutions-private.agoralab.co"]
            let rtmIpList = ["60.191.137.135"]
            
            let rtcIpList = ["60.191.137.131"]
            let rtcVerifyDomainName = "ap.130451.agora.local"
            
            let easemobChatIpList = ["180.184.183.69:6717"]
            let easemobRestIpList = ["https://zim-rtc.easemob.com:12000"]
            
            coreParameters["coreIpList"] = coreIpList
            coreParameters["easemobChatIpList"] = easemobChatIpList
            coreParameters["easemobRestIpList"] = easemobRestIpList
            
            rteParameters["rteIpList"] = rteIpList
            rteParameters["rtcIpList"] = rtcIpList
            rteParameters["rtcVerifyDomainName"] = rtcVerifyDomainName
            rteParameters["rtmIpList"] = rtmIpList
        default:
            coreParameters["environment"] = environment.rawValue
            rteParameters["environment"] = environment.rawValue
        }
        
        let parameters = ["core": coreParameters,
                          "rte": rteParameters]
        
        return parameters
    }
}



