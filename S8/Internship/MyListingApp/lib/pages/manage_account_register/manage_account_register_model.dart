import '/auth/firebase_auth/auth_util.dart';
import '/backend/backend.dart';
import '/flutter_flow/flutter_flow_icon_button.dart';
import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import '/flutter_flow/flutter_flow_widgets.dart';
import '/custom_code/actions/index.dart' as actions;
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

class ManageAccountRegisterModel extends FlutterFlowModel {
  ///  State fields for stateful widgets in this page.

  final unfocusNode = FocusNode();
  // State field(s) for inputEmail widget.
  TextEditingController? inputEmailController;
  String? Function(BuildContext, String?)? inputEmailControllerValidator;
  // State field(s) for inputPassword widget.
  TextEditingController? inputPasswordController;
  late bool inputPasswordVisibility;
  String? Function(BuildContext, String?)? inputPasswordControllerValidator;
  // State field(s) for inputPasswordConfirm widget.
  TextEditingController? inputPasswordConfirmController;
  late bool inputPasswordConfirmVisibility;
  String? Function(BuildContext, String?)?
      inputPasswordConfirmControllerValidator;

  /// Initialization and disposal methods.

  void initState(BuildContext context) {
    inputPasswordVisibility = false;
    inputPasswordConfirmVisibility = false;
  }

  void dispose() {
    unfocusNode.dispose();
    inputEmailController?.dispose();
    inputPasswordController?.dispose();
    inputPasswordConfirmController?.dispose();
  }

  /// Action blocks are added here.

  /// Additional helper methods are added here.
}
