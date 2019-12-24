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

#ifndef PLUGINSUBJECT_H_
#define PLUGINSUBJECT_H_

#include <list>
#include "IObserver.h"

class PlugInSubject {

private:
    std::list<IObserver*> *mIObserver;

protected:
    void notify(const int &eventID, const int &eventType, IDevice *device = nullptr);

public:
    PlugInSubject();
    ~PlugInSubject();
    PlugInSubject(const PlugInSubject&) = delete;
    PlugInSubject& operator=(const PlugInSubject&) = delete;
    void attach(IObserver* pIObserver);
};
#endif /* PLUGINSUBJECT_H_ */
