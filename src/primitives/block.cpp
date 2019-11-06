// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

#include <hash.h>
#include <tinyformat.h>

uint256 CBlockHeader::GetHash() const
{
    return SerializeHash(*this);
}

uint256 CBlockHeader::GetHashWithoutSign() const
{
    return SerializeHash(*this, SER_GETHASH | SER_WITHOUT_SIGNATURE);
}

std::string CBlockHeader::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlockHeader(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u)\n",
        GetHash().ToString(), nVersion, hashPrevBlock.ToString(), hashMerkleRoot.ToString(), nTime, nBits, nNonce);
    return s.str();
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u)",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce);
        s << strprintf(" vtx=%u, \n)", vtx.size());

        std::string type = "Proof-of-work";
        if (IsProofOfStake())
            type="Proof-of-stake";

        s << strprintf("( prevoutStake.ToString(), vchBlockSig=%s, proof=%s, prevoutStake=%s \n)", HexStr(vchBlockSig), type,prevoutStake.ToString());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
