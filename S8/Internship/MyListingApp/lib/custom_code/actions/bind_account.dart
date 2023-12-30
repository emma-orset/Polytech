// Automatic FlutterFlow imports
import '/backend/backend.dart';
import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import 'index.dart'; // Imports other custom actions
import '/flutter_flow/custom_functions.dart'; // Imports custom functions
import 'package:flutter/material.dart';
// Begin custom action code
// DO NOT REMOVE OR MODIFY THE CODE ABOVE!

// Set your action name, define your arguments and return parameter,
// and then add the boilerplate code using the button on the right!

import 'package:firebase_auth/firebase_auth.dart';

Future bindAccount(
  String email,
  String password,
) async {
  try {
    final credential =
        EmailAuthProvider.credential(email: email, password: password);
    final userCredential =
        await FirebaseAuth.instance.currentUser?.linkWithCredential(credential);
  } on FirebaseAuthException catch (e) {
    switch (e.code) {
      case "provider-already-linked":
        print("The provider has already been linked to the user.");
        break;
      case "invalid-credential":
        print("The provider's credential is not valid.");
        break;
      case "credential-already-in-use":
        print("The account corresponding to the credential already exists, "
            "or is already linked to a Firebase User.");
        break;
      // See the API reference for the full list of error codes.
      default:
        print("Unknown error.");
    }
  }
}
