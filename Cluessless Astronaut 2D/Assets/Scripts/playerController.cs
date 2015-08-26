using UnityEngine;
using System.Collections;

public class playerController : MonoBehaviour {
	public float jumpHeight;
	public float movementSpeed;

	public bool isSpacePressed;
	public bool isRightArrowPressed;
	public bool isLeftArrowPressed;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.Space)) {
			isSpacePressed = true;
		} else {
			isSpacePressed = false;
		}

		if (Input.GetKeyDown (KeyCode.RightArrow)) {
			isRightArrowPressed = true;
		} else {
			isRightArrowPressed = false;
		}
		if (Input.GetKeyDown (KeyCode.LeftArrow)) {
			isLeftArrowPressed = true;
		} else {
			isLeftArrowPressed = false;
		}
	}
	void FixedUpdate() {
		if(isSpacePressed){
			GetComponent<Rigidbody2D>().velocity = new Vector2(GetComponent<Rigidbody2D>().velocity.x, jumpHeight);
		}
		if (isRightArrowPressed) {
			GetComponent<Rigidbody2D>().velocity = new Vector2(movementSpeed, GetComponent<Rigidbody2D>().velocity.y);
		}
		if (isLeftArrowPressed) {
			GetComponent<Rigidbody2D>().velocity = new Vector2(-movementSpeed, GetComponent<Rigidbody2D>().velocity.y);
		}
	}
}
