{
    "targets": [
        # {
        #     "target_name": "addon-sum",
        #     "sources": ["./Addons/addon-sum.cc"]
        # },
        {
            "include_dirs": [ "<!(node -e \"require('nan')\")" ],
            "target_name": "addon-logs",
            "sources": ["./Addons/addon-log-name.cc"]
        }
    ]
}