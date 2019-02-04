// Copyright (c) 2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "PlugInSubject.h"
#include "PdmPlugInLog.h"

PlugInSubject::PlugInSubject() {
    PDM_PLUGIN_LOG_INFO("PlugInSubject:",0,"%s line: %d", __FUNCTION__,__LINE__);
    mIObserver = new (std::nothrow) std::list<IObserver*>;
}

void PlugInSubject::attach(IObserver* pIObserver){
    PDM_PLUGIN_LOG_INFO("PlugInSubject:",0,"%s line: %d", __FUNCTION__,__LINE__);
    if(pIObserver)
        mIObserver->push_back(pIObserver);
}

void PlugInSubject::notify(const int &eventID, const int &eventType, IDevice *device){
    PDM_PLUGIN_LOG_INFO("PlugInSubject:",0,"%s line: %d", __FUNCTION__,__LINE__);
    for(std::list<IObserver*>::iterator it = mIObserver->begin();
                                  it != mIObserver->end(); it++) {
        (*it)->update(eventID, eventType, device);
   }
}

PlugInSubject::~PlugInSubject() {
    mIObserver->clear();
    delete mIObserver;
    mIObserver = nullptr;
}


