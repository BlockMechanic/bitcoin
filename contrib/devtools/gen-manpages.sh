#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CYPHERD=${CYPHERD:-$BINDIR/cypherd}
CYPHERCLI=${CYPHERCLI:-$BINDIR/cypher-cli}
CYPHERTX=${CYPHERTX:-$BINDIR/cypher-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/cypher-wallet}
CYPHERQT=${CYPHERQT:-$BINDIR/qt/cypher-qt}

[ ! -x $CYPHERD ] && echo "$CYPHERD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a BTCVER <<< "$($CYPHERCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for cypherd if --version-string is not set,
# but has different outcomes for cypher-qt and cypher-cli.
echo "[COPYRIGHT]" > footer.h2m
$CYPHERD --version | sed -n '1!p' >> footer.h2m

for cmd in $CYPHERD $CYPHERCLI $CYPHERTX $WALLET_TOOL $CYPHERQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
