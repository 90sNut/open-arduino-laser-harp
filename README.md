### open-arduino-laser-harp
# The Open Arduino Laser Harp Project

Objectives:
-----------
*  Make a honest-to-godness frameless laser harp with reasonabily functionability and affordable for diy.
*  Trace the main issues found in the development for the diyers
*  ALERT about using lasers
*  Make a unified wiki!
*  Turn the code open in way of been improved by each diyer.
*  And more? :)

# Branching Guidelines #

### Main Branches: 

*  **master**: contains only the instructions/guidelines/main info of the project 

*  **dev**: this is the central branch, where all code is merged into, from which should be done automated continuos integration. This is meant to ensure code consistency
 
### Features Branches: 

*  **feat-***: any new feature being developed. These branches should ever be merged into develop before releasing
 
### Release Branches: 

*  **release-vX**: code being prepared to release, where X is the major version. As of packaging a branch, a TAG should be created at it, named "**vX.Y**", where Y is the minor version. Any hotfix done to the branch should be tagged again with minor version incremented when pakaged/released again.

### Naming conventions:

*  branch names should be lowercase, have only letter and numbers and spaces replaced by hyphens