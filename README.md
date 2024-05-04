# EHCTF 2024

Repository for maintaining and building challenge images for EHCTF 2024 - HolaCTF 2024 Phase 2.

Powered by [GZ::CTF](https://github.com/GZTimeWalker/GZCTF)

## How to connect to the CTF platform

> This event will use OpenVPN to access, please use the VPN provided to connect to the CTF platform.

URL: https://ctf.ehc-fptu.club/

VPN: [OpenVPN](https://openvpn.net/client/) and [VPN Profile](https://drive.google.com/file/d/1jSSIK-QNsTlavpa8qf02-BLxeYh6BePx/view?usp=sharing)


## Challenge Designing Specification

- All challengs should follow the challenge specification of GZCTF. Dockerfile of the challenge should be placed to `challenges` directory.
- For each challenge, please create a specific branch with name catagory/challenge_name and develop in that branch. Finally squash merge to `main`.
- For those base images that can be shared and reused by different challengs, please place then in the `base` directory. For example, `xinetd`, `python`, `php`, etc.

## Challenges Category

> Please tag the challenge with the corresponding category.

| Category | Description |
| --- | --- |
| Misc | Miscellaneous |
| Crypto | Cryptography |
| Pwn | Binary Exploitation |
| Web | Web Exploitation |
| Reverse | Reverse Engineering |
| Blockchain | Blockchain |
| Forensics | Forensics |
| Hardware | Hardware |
| Mobile | Mobile Security |
| PPC | Programming Puzzles and Challenges |
| AI | Artificial Intelligence |

## Challenges Type

> Please tag the challenge with the corresponding type. For Dynamic Challenges, please get flag from the `GZCTF` environment variable.

| Type | Description |
| --- | --- |
| Static Attachments | Shared attachments, any flag can be submitted |
| Static Container | Shared container, any flag can be submitted |
| Dynamic Attachments | Distribute attachment by team, ensuring that the number of attachments is greater than the number of teams |
| Dynamic Container | Automatic flag generation, unique for each team |

With Dynamic Container, you will get flag from GZCTF_FLAG environment variable

## Challenges List

Challenge Name | Category | Difficulty | Tag | Author
--- | --- | --- | --- | ---
One number SQL | Web | Normal | SQL | n1gthf4ll

## Difficulty and Points

| Difficulty | Baby | Trivial | Easy | Normal | Medium | Hard | Expert | Insane |
|------------|------|---------|------|--------|--------|------|--------|--------|
| Initial Points | 200 | 500 | 1000 | 1000 | 1000 | 1000 | 1000 | 1000 |
| Minimum Points Ratio for Challenge | 50% | 20% | 20% | 20% | 20% | 20% | 30% | 30% |
| Minimum Points for Challenge | 100 | 100 | 200 | 200 | 200 | 200 | 300 | 300 |
| Difficulty Factor | 5.0 | 5.0 | 7.0 | 10.0 | 13.0 | 20.0 | 20.0 | 25.0 |
| Number of solves when reaching 50% pts | - | 6 | 7 | 10 | 14 | 20 | 25 | 30 |


## Repository Structure

```
.github/workflows/                      # github actions
    └── chal.<category>.<name>.yml      # Building script for each challenge
base/                                   # Base image
challenges/                             # Challenges directory
    ├── challenge1/
    │   ├── build/                      # Challenge building directory
    │   │   ├── Dockerfile
    │   │   └── more...
    │   ├── attachments/                # Challenge attachment
    │   └── README.md
    ├── challenge2/
    └── more...
```

## File Directory

Please write the `Dockerfile` and place it in challenges then add corresponding building task action to .github/workflows. The naming should follow the format of challenge.<category_name>.<challenge_name>.yml. The challenge needs to follow the GZCTF question specification.

- `base` directory

`base` contains the base images that can be shared and reused by some challenges, including xinetd, python image exposed based on xinetd.

- `challenges` directory

`challenges` contains Dockerfile of challenge and other files related to the challenges.

## Exposed ports

Please do not use `EXPOSE` to expose ports in the challenge Dockerfile, because GZ::CTF will automatically map the specified port to a random port on the host. If `EXPOSE` is used in the Dockerfile, it will cause the challenge to expose multiple ports and occupy port resources, and even expose safety risks.
