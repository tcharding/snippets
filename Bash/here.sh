#!/usr/bin/bash
#
# Feed interactive input to script using here document

set -o nounset

bash interactive.sh <<EOF
Big Kev
YES
EOF

exit 0
