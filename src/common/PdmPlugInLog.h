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

#ifndef _PDM_PLUGIN_LOG_H
#define _PDM_PLUGIN_LOG_H

#include <PmLogLib.h>

#define PDM_PLUGIN_LOG_CRITICAL(...)   PmLogMsg(PDM_PLUGIN_GetPmLogContext(), Critical, "", 0, __VA_ARGS__)
#define PDM_PLUGIN_LOG_ERROR(...)      PmLogMsg(PDM_PLUGIN_GetPmLogContext(), Error, "", 0, __VA_ARGS__)
#define PDM_PLUGIN_LOG_WARNING(...)    PmLogMsg(PDM_PLUGIN_GetPmLogContext(), Warning, "", 0, __VA_ARGS__)
#define PDM_PLUGIN_LOG_INFO(msgID,...) PmLogMsg(PDM_PLUGIN_GetPmLogContext(), Info, msgID, __VA_ARGS__)
#define PDM_PLUGIN_LOG_DEBUG(...)      PmLogMsg(PDM_PLUGIN_GetPmLogContext(), Debug, NULL, 0, __VA_ARGS__)

PmLogContext PDM_PLUGIN_GetPmLogContext();

#endif //_PDM_PLUGIN_LOG_H
