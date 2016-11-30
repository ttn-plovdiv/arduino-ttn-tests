Connect to [The Things Network](https://www.thethingsnetwork.org/)
using ABP

1. Register in the [staging dashboard](https://staging.thethingsnetwork.org).

2. Create an application.

3. Register `ABP` device

4. Create a `Credentials.h` file from our example.

    cp src/Credentials.example.h src/Credentials.h

5. Get the `Dev Address`, `Network Session Key` and `App Session Key` of your newly created device and paste them in `src/Credentials.h`.

6. Upload your sketch

You should see coming packets in the dashboard.