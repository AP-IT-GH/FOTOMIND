# Release engineering explained

## Branches:
 * feature 1,2,3: development branches
 * master: unstable branch (fresh code is merged in master) (normally stable, sometimes some errors)
 * release: stable branch (without build errors!) ("always have a working version")

## Workflow

![Release engineering diagram](https://github.com/AP-Elektronica-ICT/smart-objects/blob/master/1_source/3_ReleaseEngineering/workflow.png?raw=true)

 1. Developers push changes to their own branch: feature 1, feature 2, feature 3,...
 2. Send pull request to merge with master
 3. Release engineers evaluate pull requests and merge master with feature (Rien, Dries)
 4. Release engineers test master branch (does it build, succesfull unit tests, manual inspection...)
 5. If everything is ok -> send pull request to release branch
 6. merge release with master
 7. Tag release with version number
