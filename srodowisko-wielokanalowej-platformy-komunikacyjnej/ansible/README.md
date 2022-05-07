# Introduction
This directory contains the resources needed to successfully run the `Ansible` playbooks (the .yaml files). If you
need to know more about `Ansible`, I welcome you to its [home page](https://www.ansible.com/).

## Steps
* clone the repository
* install `ansible CLI`
* prepare teh host for the application (system that will run the application)
* make sure the system with the clone of the repository has an SSH access to the host (exchange SSH keys)
* list the IP address of the host inside [`inventory`](./inventory) (one per each line)
* change the URL of the API to a public address of the host
* run the playbook
