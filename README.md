**RESTCONF** (RFC8040) - a programmatic interface for accessing data defined in YANG, using the datastore concepts defined in the Network Configuration Protocol (NETCONF).

```
https://<ADDRESS>/<ROOT>/data/<[YANG MODULE:]CONTAINER>/<LEAF>[?<OPTIONS>]
  ADDRESS - Of the RESTCONF Agent
  ROOT - The main entry point for RESTCONF requests (Discoverable at https://<ADDRESS>/.well-known/host-meta)
  data - The RESTCONF API resource type for data ("operations" resource type for RPC)
  [YANG MODULE:]CONTAINER - The base model container being used. Providing the module name is optional.
  LEAF - An individual element from within the container
  [?<OPTIONS>] - optional parameters that impact returned results.
```

## Build
```
make
make install
```

# Develop
```
sudo apt-get install libglib2.0-dev libfcgi-dev indent lcov valgrind curl
make demo
make indent
make test
make test VALGRIND=no
google-chrome gcov/index.html
```

# Examples
```
curl -sX PUT http://localhost/restconf/data -d '{"ietf-interfaces:interfaces":{"interface":{"name":"eth1","type":"iana-if-type:ethernetCsmacd","enabled":true}}}'
```

```
curl -G http://localhost/restconf/data/ietf-interfaces:interfaces
[
  {
    "ietf-interfaces:interfaces": {
      "interface":[
        {
          "name": "eth1",
          "type": "iana-if-type:ethernetCsmacd",
          "enabled": true,
         }
      ]
    }
  }
]
```

```
curl -G http://localhost/restconf/data/interfaces/interface/name=eth1
[
  {
    "name": "eth1",
    "type": "iana-if-type:ethernetCsmacd",
    "enabled": true,
  }
]
```

```
curl -G http://localhost/restconf/data/interfaces/interface=eth1/type
{
  "ietf-interfaces:type": "iana-if-type:ethernetCsmacd" 
}
```

```
curl -s -X DELETE  http://localhost/restconf/data/ietf-interfaces:interfaces
```