#!/xhbin/bash
read foo<<'EOF';eval $foo
echo '#!/bin/bash';echo 'read foo<<'"'EOF'"';eval $foo';echo $foo;echo EOF
EOF