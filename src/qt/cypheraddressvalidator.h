// Copyright (c) 2011-2014 The Cypher Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CYPHER_QT_CYPHERADDRESSVALIDATOR_H
#define CYPHER_QT_CYPHERADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CypherAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CypherAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Cypher address widget validator, checks for a valid cypher address.
 */
class CypherAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CypherAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CYPHER_QT_CYPHERADDRESSVALIDATOR_H
