import '/auth/firebase_auth/auth_util.dart';
import '/backend/backend.dart';
import '/backend/firebase_storage/storage.dart';
import '/components/no_tag/no_tag_widget.dart';
import '/flutter_flow/flutter_flow_drop_down.dart';
import '/flutter_flow/flutter_flow_icon_button.dart';
import '/flutter_flow/flutter_flow_radio_button.dart';
import '/flutter_flow/flutter_flow_theme.dart';
import '/flutter_flow/flutter_flow_util.dart';
import '/flutter_flow/flutter_flow_widgets.dart';
import '/flutter_flow/form_field_controller.dart';
import '/flutter_flow/upload_data.dart';
import '/custom_code/actions/index.dart' as actions;
import '/flutter_flow/custom_functions.dart' as functions;
import 'dart:async';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

class CreateMediaModel extends FlutterFlowModel {
  ///  Local state fields for this page.

  List<String> listTags = [];
  void addToListTags(String item) => listTags.add(item);
  void removeFromListTags(String item) => listTags.remove(item);
  void removeAtIndexFromListTags(int index) => listTags.removeAt(index);
  void updateListTagsAtIndex(int index, Function(String) updateFn) =>
      listTags[index] = updateFn(listTags[index]);

  ///  State fields for stateful widgets in this page.

  final unfocusNode = FocusNode();
  final formKey = GlobalKey<FormState>();
  // State field(s) for InputTitle widget.
  TextEditingController? inputTitleController;
  String? Function(BuildContext, String?)? inputTitleControllerValidator;
  String? _inputTitleControllerValidator(BuildContext context, String? val) {
    if (val == null || val.isEmpty) {
      return 'Title is required';
    }

    if (val.length < 1) {
      return 'Title is required';
    }
    if (val.length > 200) {
      return 'Title cannot exceed 200 characters';
    }

    return null;
  }

  // State field(s) for RadioButtonRW widget.
  FormFieldController<String>? radioButtonRWValueController;
  // State field(s) for InputType widget.
  TextEditingController? inputTypeController;
  String? Function(BuildContext, String?)? inputTypeControllerValidator;
  String? _inputTypeControllerValidator(BuildContext context, String? val) {
    if (val == null || val.isEmpty) {
      return 'Type is required';
    }

    if (val.length < 1) {
      return 'Type is required';
    }
    if (val.length > 100) {
      return 'Type cannot exceed 100 characters';
    }

    return null;
  }

  // State field(s) for InputTag widget.
  TextEditingController? inputTagController;
  String? Function(BuildContext, String?)? inputTagControllerValidator;
  // Stores action output result for [Custom Action - toLower] action in Button widget.
  String? lowerTag;
  // State field(s) for DropDownProgress widget.
  String? dropDownProgressValue;
  FormFieldController<String>? dropDownProgressValueController;
  // State field(s) for InputStop widget.
  TextEditingController? inputStopController;
  String? Function(BuildContext, String?)? inputStopControllerValidator;
  // State field(s) for InputURL widget.
  TextEditingController? inputURLController;
  String? Function(BuildContext, String?)? inputURLControllerValidator;
  // State field(s) for InputAuthors widget.
  TextEditingController? inputAuthorsController;
  String? Function(BuildContext, String?)? inputAuthorsControllerValidator;
  // State field(s) for DropDownStatus widget.
  String? dropDownStatusValue;
  FormFieldController<String>? dropDownStatusValueController;
  // State field(s) for InputDetails widget.
  TextEditingController? inputDetailsController;
  String? Function(BuildContext, String?)? inputDetailsControllerValidator;
  bool isDataUploading = false;
  FFUploadedFile uploadedLocalFile =
      FFUploadedFile(bytes: Uint8List.fromList([]));
  String uploadedFileUrl = '';

  // Stores action output result for [Custom Action - toLower] action in Button widget.
  String? lowerType;
  Completer<List<MediasRecord>>? firestoreRequestCompleter;

  /// Initialization and disposal methods.

  void initState(BuildContext context) {
    inputTitleControllerValidator = _inputTitleControllerValidator;
    inputTypeControllerValidator = _inputTypeControllerValidator;
  }

  void dispose() {
    unfocusNode.dispose();
    inputTitleController?.dispose();
    inputTypeController?.dispose();
    inputTagController?.dispose();
    inputStopController?.dispose();
    inputURLController?.dispose();
    inputAuthorsController?.dispose();
    inputDetailsController?.dispose();
  }

  /// Action blocks are added here.

  /// Additional helper methods are added here.

  String? get radioButtonRWValue => radioButtonRWValueController?.value;
  Future waitForFirestoreRequestCompleted({
    double minWait = 0,
    double maxWait = double.infinity,
  }) async {
    final stopwatch = Stopwatch()..start();
    while (true) {
      await Future.delayed(Duration(milliseconds: 50));
      final timeElapsed = stopwatch.elapsedMilliseconds;
      final requestComplete = firestoreRequestCompleter?.isCompleted ?? false;
      if (timeElapsed > maxWait || (requestComplete && timeElapsed > minWait)) {
        break;
      }
    }
  }
}
