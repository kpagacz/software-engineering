# Create the root user with the password 'passwd'
# Login as the root

# Creates two user groups
pw group add zwierzaki
pw group add animals

# Creates an account pies
pw user add -n pies -c "Burek Buda" -e +2o -p +2w -G zwierzaki -s /bin/sh -m -M 0700 -w yes

# Creates an account dog
pw user add -n dog -c "Rex Barks" -m -M 0700 -s /bin/csh -w yes -G animals
