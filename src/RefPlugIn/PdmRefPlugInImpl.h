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

#ifndef PDMREFPLUGINIMPL_H_
#define PDMREFPLUGINIMPL_H_

#include <Plugin-Api.h>
#include "PlugInSubject.h"


class PdmRefPlugInImpl :  public PluginBase, public PlugInSubject {
private:
    guint m_resumeDone;
    static gboolean resumeDoneNotification(PdmRefPlugInImpl *pdmRefPlugInImpl);
public:
    PdmRefPlugInImpl(Mananger *manager, LSHandle *lunaHandle);
    virtual ~PdmRefPlugInImpl() = default;
    virtual bool init() override;
    virtual void deInit() override;
    virtual void notifyChange(const int &eventID, const int &eventType, IDevice *device = nullptr) override;

};
#endif /* PDMREFPLUGINIMPL_H_ */
