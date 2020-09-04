// Copyright (c) 2019-2020 LG Electronics, Inc.
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

#include "PdmRefPlugInImpl.h"
#include "PdmPlugInLog.h"
#define RESUME_DONE_TIMEOUT 12

Plugin *instantiatePlugin(Mananger *manager, LSHandle *lunaHandle) {
    return new (std::nothrow) PdmRefPlugInImpl(manager, lunaHandle);
}

PdmRefPlugInImpl::PdmRefPlugInImpl(Mananger *manager, LSHandle *lunaHandle):
                        PluginBase(manager, lunaHandle) {

}

bool PdmRefPlugInImpl::init() {
    PDM_PLUGIN_LOG_INFO("PdmRefPlugInImpl:",0,"%s line: %d", __FUNCTION__,__LINE__);
    attach(m_Manager);
    m_resumeDone = g_timeout_add_seconds(RESUME_DONE_TIMEOUT, (GSourceFunc) resumeDoneNotification, this);
    return true;
}

void PdmRefPlugInImpl::deInit() {
    if(m_resumeDone){
        g_source_remove(m_resumeDone);
        m_resumeDone = 0;
    }
}
void PdmRefPlugInImpl::notifyChange(const int &eventID, const int &eventType, IDevice *device) {
    notify(eventID, eventType, device);
 }

gboolean PdmRefPlugInImpl::resumeDoneNotification(PdmRefPlugInImpl *pdmRefPlugInImpl) {
    PDM_PLUGIN_LOG_INFO("PdmRefPlugInImpl:",0,"%s line: %d Notifying resume done", __FUNCTION__,__LINE__);
    pdmRefPlugInImpl->notifyChange(PlugInEvent, POWER_STATE_RESUME_DONE);
    if(pdmRefPlugInImpl->m_resumeDone){
        g_source_remove(pdmRefPlugInImpl->m_resumeDone);
        pdmRefPlugInImpl->m_resumeDone = 0;
    }
    return false;
}
