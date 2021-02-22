/*
 * This file is part of KDiff3
 *
 * SPDX-FileCopyrightText: 2021-2021 David Hallas, david@davidhallas.dk
 * SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "CompositeIgnoreList.h"

void CompositeIgnoreList::enterDir(const QString& dir, const DirectoryList& directoryList) {
    for (const auto& ignoreList : m_ignoreLists) {
        ignoreList->enterDir(dir, directoryList);
    }
}

bool CompositeIgnoreList::matches(const QString& dir, const QString& text, bool bCaseSensitive) const {
    for (const auto& ignoreList : m_ignoreLists) {
        if (ignoreList->matches(dir, text, bCaseSensitive)) {
            return true;
        }
    }
    return false;
}

void CompositeIgnoreList::addIgnoreList(std::unique_ptr<IgnoreList> ignoreList) {
    m_ignoreLists.push_back(std::move(ignoreList));
}